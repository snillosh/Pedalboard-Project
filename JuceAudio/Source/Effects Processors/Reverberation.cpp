//
//  Reverb.cpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

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
}

void Reverberation::setParameter1(float input)
{
    fFeedbackGain = (input / 10) * 0.5;
}

void Reverberation::setParameter2(float input)
{
    fDelayTime = (input / 10) * 0.8;
}

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
