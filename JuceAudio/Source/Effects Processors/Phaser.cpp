/*
  ==============================================================================

    Phaser.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Phaser.hpp"


Phaser::Phaser()
{
    for (auto n = 0; n < numStages; n++ )
    {
        allpassFilters.add(new juce::dsp::FirstOrderTPTFilter<float>());
        allpassFilters[n]->setType(juce::dsp::FirstOrderTPTFilterType::allpass);
        
    }
}

Phaser::~Phaser()
{
    
}

void Phaser::setParameter1(float input)
{
}
float Phaser::getParameter1() const
{
}
//----------------------------------------
void Phaser::setParameter2(float input)
{
}
float Phaser::getParameter2() const
{
}
//----------------------------------------
void Phaser::setParameter3(float input)
{
}
float Phaser::getParameter3() const
{
}
//----------------------------------------
void Phaser::setParameter4(float input)
{
}
float Phaser::getParameter4() const
{
}
//----------------------------------------
void Phaser::setParameter5(float input)
{
}
float Phaser::getParameter5() const
{
}
//----------------------------------------
void Phaser::initialiser(double setSampleRate)
{
    dsp::ProcessSpec spec;
    sampleRate = setSampleRate;
    rateLFO.setSampleRate(sampleRate);
    for (auto n = 0; n < numStages; ++n)
    {
        allpassFilters[n]->prepare (spec);
        allpassFilters[n]->reset();
    }
}

void Phaser::updateFilter()
{
    rate = 0.04f;
    depth = 1.0f;
    mix = 0.5f;
    feedback = 0.8f;
    rateLFO.setFrequency(rate);
    rateLFO.setGain(depth);
    for (auto n = 0; n < numStages; n++)
    {
        float phaserPositionInHertz = (rateLFO.nextSample() * 0.5f) + 0.5f;
        phaserPositionInHertz = (phaserPositionInHertz * 9702.0f) + 98.0f;
        allpassFilters[n]->setCutoffFrequency(phaserPositionInHertz);
        
    }
}

float Phaser::process(float input)
{
    if (isOn())
    {
        updateFilter();
        
        float allpass1 = allpassFilters[0]->processSample(0, input) + (allpassOutFinal * feedback);
        float allpass2 = allpassFilters[1]->processSample(0, allpass1);
        float allpass3 = allpassFilters[2]->processSample(0, allpass2);
        allpassOutFinal = allpassFilters[3]-> processSample(0, allpass3);
        output = (mix * allpassOutFinal) + ((1.0f - mix) * input);
        return output;
    }
    else
        return input;
}


