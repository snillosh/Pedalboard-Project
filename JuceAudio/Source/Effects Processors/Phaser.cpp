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
        allpassFilters[n]->snapToZero();
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
void Phaser::initialise()
{
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
    rate = 10.0f;
    depth = 0.8f;
    mix = 0.5f;
    feedback = 0.8f;
    rateLFO.setFrequency(rate);
    rateLFO.setGain(depth);
    float phaserPositionInHertz = (rateLFO.nextSample() * 0.5f) + 0.5f;
    phaserPositionInHertz = (phaserPositionInHertz * 9702.0f) + 98.0f;
    DBG("PHASE POSITON IN HERTZ: " << phaserPositionInHertz);
    for (auto n = 0; n < numStages; n++)
    {
        allpassFilters[n]->setCutoffFrequency(phaserPositionInHertz);
        allpassFilters[n]->snapToZero();
    }
}

float Phaser::process(float input)
{
    if (isOn())
    {
        updateFilter();
        float allpass1 = allpassFilters[0]->processSample(1, input) + (allpassOutFinal * feedback);
        float allpass2 = allpassFilters[1]->processSample(1, allpass1);
        float allpass3 = allpassFilters[2]->processSample(1, allpass2);
        allpassOutFinal = allpassFilters[3]-> processSample(1, allpass3);
        output = (mix * allpassOutFinal) + ((1.0f - mix) * input);
        return output;
    }
    else
    {
        return input;
    }
}


