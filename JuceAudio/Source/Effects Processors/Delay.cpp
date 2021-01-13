//
//  Delay.cpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

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
    iBufferSize = (int)(2.0f * fSR);
    pfCircularBuffer = new float[iBufferSize];
    for (int x = 0; x<iBufferSize; x++)
        pfCircularBuffer[x] = 0;
    
    iBufferWritePos = 0;
}

float Delay::process(float input)
{
    iBufferWritePos++;
    if (iBufferWritePos > (iBufferSize -1))
        iBufferWritePos = 0;
    pfCircularBuffer[iBufferWritePos] = input;
    signed int iBufferReadPos = iBufferWritePos - (0.25f * fSR);
    if (iBufferReadPos > (iBufferSize -1 ))
        iBufferReadPos = 0;
    fDelSig = pfCircularBuffer[iBufferReadPos] * 0.2;
    return fDelSig;
}

