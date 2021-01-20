/*
  ==============================================================================

    Reverb.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

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
    fSR = 44100;
    iBufferSize = (int)(2.0f * fSR);
    pfCircularBuffer = new float[iBufferSize];
    for (int x = 0; x<iBufferSize; x++)
        pfCircularBuffer[x] = 0;
    iBufferWritePos = 0;
    fDelayTime = 0.8;
    fFeedbackGain = 0.7;
    //dsp::ProcessSpec spec;
}
//------------------------------------------------
void Reverberation::setParameter1(float input)
{
    fFeedbackGain = (input / 10) * 0.5;
}
float Reverberation::getParameter1() const
{
    return fFeedbackGain;
}
//------------------------------------------------
void Reverberation::setParameter2(float input)
{
    fCutOff = (input / 10) * 5000;
}
float Reverberation::getParameter2() const
{
    return fCutOff;
}
//------------------------------------------------
void Reverberation::setParameter3(float input)
{
    fDelayTime = (input / 10) * 0.8;
}
float Reverberation::getParameter3() const
{
    return fDelayTime;
}
//------------------------------------------------
void Reverberation::setParameter4(float input)
{
}
float Reverberation::getParameter4() const
{
}
//------------------------------------------------
void Reverberation::setParameter5(float input)
{
}
float Reverberation::getParameter5() const
{
}
//------------------------------------------------
float Reverberation::process(float input)
{
    if (isOn())
    {
        fOut = fDelSig + input;
        iBufferWritePos++;
        if (iBufferWritePos > (iBufferSize -1))
            iBufferWritePos = 0;
        pfCircularBuffer[iBufferWritePos] = fOut;
        iBufferReadPos = iBufferWritePos - (fDelayTime * fSR);
        if (iBufferReadPos < 0){
            iBufferReadPos = (iBufferSize - (fDelayTime * fSR)) + iBufferWritePos;
        }
        else
        {
            iBufferReadPos = iBufferWritePos - (fDelayTime * fSR);
        }
        
        if (iBufferReadPos > (iBufferSize -1 ))
            iBufferReadPos = 0;
        fDelSig = pfCircularBuffer[iBufferReadPos] * fFeedbackGain;
        return fOut;
    }
    else
    {
        return input;
    }
}
