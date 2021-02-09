/*
  ==============================================================================

    Compressor.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Compressor.hpp"


Compressor::Compressor()
{
    
}

Compressor::~Compressor()
{
    
}
//------------------------------------------------
void Compressor::setParameter1(float input)
{
}
float Compressor::getParameter1() const
{
    return 0;
}
//---------------------------------------------
void Compressor::setParameter2(float input)
{
    depth = input / 10.0f;
}
float Compressor::getParameter2() const
{
    return depth;
}
//---------------------------------------------
void Compressor::setParameter3(float input)
{
    rate = input * 2.0f;
}
float Compressor::getParameter3() const
{
    return rate;
}
//---------------------------------------------
void Compressor::setParameter4(float input)
{

}
float Compressor::getParameter4() const
{
    return 0;
}
//---------------------------------------------
void Compressor::setParameter5(float input)
{
    
}
float Compressor::getParameter5() const
{
    return 0;
}
//---------------------------------------------
void Compressor::intitialise()
{
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    LFO.setSampleRate(sampleRate);
}

void Compressor::updateLFO()
{
    LFO.setFrequency(rate);
    LFO.setGain(depth);
}

float Compressor::process(float input)
{
    if (isOn())
    {
        updateLFO();
        auto outputGain = (LFO.nextSample() * 0.5) + 0.5;
        float outputValue = outputGain * input;
        return outputValue;
        
    }
    else
    {
        return input;
    }
        
}


