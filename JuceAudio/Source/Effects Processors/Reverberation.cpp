/*
  ==============================================================================

    Reverb.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter
    DSP code: Bevan Salter
  ==============================================================================
*/

#include "Reverberation.hpp"



Reverberation::Reverberation()
{
    
}

Reverberation::~Reverberation()
{
    
}

void Reverberation::initialise()
{
    cutOff = 50.0f;
    feedbackGain = 0.0f;
    delayTime1 = 0.1f;
    delayTime2 = 0.033f;
    delayTime3 = 0.015;
    lowPassFilter.add(new juce::dsp::FirstOrderTPTFilter<float>()); // adds 1 filter
    lowPassFilter[0]->setType(juce::dsp::FirstOrderTPTFilterType::lowpass); // makes it lowpass
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    lowPassFilter[0]->prepare(spec);
    lowPassFilter[0]->reset();
    iBufferSize = (int)(2.0f * sampleRate);
    pfCircularBuffer = new float[iBufferSize];
    for (int x = 0; x<iBufferSize; x++)
        pfCircularBuffer[x] = 0;
    iBufferWritePos = 0;
}

void Reverberation::updateFilter()
{
    lowPassFilter[0]->setCutoffFrequency(cutOff);
}
//------------------------------------------------
void Reverberation::setParameter1(float input)
{
}
float Reverberation::getParameter1() const
{
    return 0;
}
//------------------------------------------------
void Reverberation::setParameter2(float input)
{
    cutOff = ((input / 10) * 4950) + 50;
}
float Reverberation::getParameter2() const
{
    return cutOff;
}
//------------------------------------------------
void Reverberation::setParameter3(float input)
{
    feedbackGain = input / 20;
}
float Reverberation::getParameter3() const
{
    return feedbackGain;
}
//------------------------------------------------
void Reverberation::setParameter4(float input)
{
}
float Reverberation::getParameter4() const
{
    return 0;
}
//------------------------------------------------
void Reverberation::setParameter5(float input)
{
}
float Reverberation::getParameter5() const
{
    return 0;
}
//------------------------------------------------
float Reverberation::process(float input) // uses 3 short delays
{
    if (isOn())
    {
        updateFilter();
        fOut = fDelSigSummed + input;
        iBufferWritePos++;
        if (iBufferWritePos > (iBufferSize -1))
            iBufferWritePos = 0;
        pfCircularBuffer[iBufferWritePos] = fOut;
        //----------------------------------------------------------------------------------
        iBufferReadPos1 = iBufferWritePos - (delayTime1 * sampleRate);
        if (iBufferReadPos1 < 0){
            iBufferReadPos1 = (iBufferSize - (delayTime1 * sampleRate)) + iBufferWritePos;
        }
        else
        {
            iBufferReadPos1 = iBufferWritePos - (delayTime1 * sampleRate);
        }
        
        if (iBufferReadPos1 > (iBufferSize -1 ))
            iBufferReadPos1 = 0;
        fDelSig1 = pfCircularBuffer[iBufferReadPos1] * feedbackGain;
        //----------------------------------------------------------------------------------
        iBufferReadPos2 = iBufferWritePos - (delayTime2 * sampleRate);
        if (iBufferReadPos2 < 0){
            iBufferReadPos2 = (iBufferSize - (delayTime2 * sampleRate)) + iBufferWritePos;
        }
        else
        {
            iBufferReadPos2 = iBufferWritePos - (delayTime2 * sampleRate);
        }
        
        if (iBufferReadPos2 > (iBufferSize -1 ))
            iBufferReadPos2 = 0;
        fDelSig2 = pfCircularBuffer[iBufferReadPos2] * feedbackGain;
        //----------------------------------------------------------------------------------
        iBufferReadPos3 = iBufferWritePos - (delayTime3 * sampleRate);
        if (iBufferReadPos3 < 0){
            iBufferReadPos3 = (iBufferSize - (delayTime3 * sampleRate)) + iBufferWritePos;
        }
        else
        {
            iBufferReadPos3 = iBufferWritePos - (delayTime3 * sampleRate);
        }
        
        if (iBufferReadPos3 > (iBufferSize -1 ))
            iBufferReadPos3 = 0;
        fDelSig3 = pfCircularBuffer[iBufferReadPos3] * feedbackGain;
        //----------------------------------------------------------------------------------
        fDelSigSummed = fDelSig1 + fDelSig2 + fDelSig3;
        fDelSigSummed = lowPassFilter[0]->processSample(0, fDelSigSummed);
        
        return fOut;
    }
    else
    {
        return input;
    }
}
