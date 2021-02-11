/*
  ==============================================================================

    LFO.cpp
    Created: 26 Jan 2021 6:51:38pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "LFO.h"
#include <cmath>

LFO::LFO()
{
    
}

LFO::~LFO()
{
    
}


float LFO::nextSample()
{
    phaseIncrement = (MathConstants<float>::twoPi * oscillatorFrequency) / sampleRate;
    
    phasePosition = phasePosition + phaseIncrement;
    if (phasePosition > MathConstants<float>::twoPi)
    {
        phasePosition = phasePosition - MathConstants<float>::twoPi;
    }
    return std::sin(phasePosition) * gain;
}

void LFO::setFrequency(float frequency)
{
    oscillatorFrequency = frequency;
}

void LFO::setSampleRate(float newSampleRate)
{
    sampleRate = newSampleRate;
}

void LFO::setGain(float newGain)
{
    gain = newGain;
}
