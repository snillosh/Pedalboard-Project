/*
  ==============================================================================

    Delay.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter
    DSP code: Bevan Salter
  ==============================================================================
*/
#include "Delay.hpp"


Delay::Delay()
{

}

Delay::~Delay()
{
    
}

void Delay::initialise()
{
    fSR = 44100;
    iBufferSize = (int)(2.0f * fSR); // set a 2 second buffer
    pfCircularBuffer = new float[iBufferSize];
    for (int x = 0; x<iBufferSize; x++)
        pfCircularBuffer[x] = 0;
    iBufferWritePos = 0;
    fDelayTime = 0.0;
    fFeedbackGain = 0.0;
}
//Mutator
void Delay::setParameter1(float input)
{
}
// ACCESSOR
float Delay::getParameter1() const
{
    return 0;
}
//---------------------------------------------
void Delay::setParameter2(float input)
{
    fDelayTime = (input / 10) * 0.8;
}
float Delay::getParameter2() const
{
    return fDelayTime;
}
//---------------------------------------------
void Delay::setParameter3(float input)
{
    fFeedbackGain = (input / 10) * 0.7;
}
float Delay::getParameter3() const
{
    return fFeedbackGain;
}
//---------------------------------------------
void Delay::setParameter4(float input)
{
}
float Delay::getParameter4() const
{
    return 0;
}
//---------------------------------------------
void Delay::setParameter5(float input)
{
}
float Delay::getParameter5() const
{
    return 0;
}
//---------------------------------------------
float Delay::process(float input)
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

