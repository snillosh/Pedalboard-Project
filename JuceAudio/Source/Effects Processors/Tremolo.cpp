/*
  ==============================================================================

    Compressor.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Tremolo.hpp"


Tremolo::Tremolo()
{
    
}

Tremolo::~Tremolo()
{
    
}
//------------------------------------------------
void Tremolo::setParameter1(float input)
{
}
float Tremolo::getParameter1() const
{
    return 0;
}
//---------------------------------------------
void Tremolo::setParameter2(float input)
{
    depth = input / 10.0f;
}
float Tremolo::getParameter2() const
{
    return depth;
}
//---------------------------------------------
void Tremolo::setParameter3(float input)
{
    rate = input * 2.0f;
}
float Tremolo::getParameter3() const
{
    return rate;
}
//---------------------------------------------
void Tremolo::setParameter4(float input)
{

}
float Tremolo::getParameter4() const
{
    return 0;
}
//---------------------------------------------
void Tremolo::setParameter5(float input)
{
    
}
float Tremolo::getParameter5() const
{
    return 0;
}
//---------------------------------------------
void Tremolo::intitialise()
{
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    LFO.setSampleRate(sampleRate);
}

void Tremolo::updateLFO()
{
    LFO.setFrequency(rate);
    LFO.setGain(depth);
}

float Tremolo::process(float input)
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


