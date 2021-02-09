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
    return 0;
}
//----------------------------------------
void Phaser::setParameter2(float input)
{
    depth = input / 10;
}
float Phaser::getParameter2() const
{
    return depth;
}
//----------------------------------------
void Phaser::setParameter3(float input)
{
    feedback = input / 10;
}
float Phaser::getParameter3() const
{
    return feedback;
}
//----------------------------------------
void Phaser::setParameter4(float input)
{
    rate = input * 2.0f;
}
float Phaser::getParameter4() const
{
    return rate;
}
//----------------------------------------
void Phaser::setParameter5(float input)
{
}
float Phaser::getParameter5() const
{
    return 0;
}
//----------------------------------------
void Phaser::initialise()
{
    mix = 0.5f;
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    rateLFO.setSampleRate(sampleRate);
    
    for (auto n = 0; n < numStages; ++n)
    {
        allpassFilters[n]->prepare (spec);
        allpassFilters[n]->reset();
    }
}

void Phaser::updateFilter()
{
    rateLFO.setFrequency(rate);
    rateLFO.setGain(depth);
    float phaserPositionInHertz = (rateLFO.nextSample() * 0.5f) + 0.5f;
    phaserPositionInHertz = (phaserPositionInHertz * 9702.0f) + 98.0f;
    for (auto n = 0; n < numStages; n++)
    {
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
    {
        return input;
    }
}


