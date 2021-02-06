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
    dsp::ProcessSpec spec;
    reverb.setEnabled(true);
    reverb.prepare(spec);
}
//------------------------------------------------
void Reverberation::setParameter1(float input)
{
}
float Reverberation::getParameter1() const
{
}
//------------------------------------------------
void Reverberation::setParameter2(float input)
{
}
float Reverberation::getParameter2() const
{
}
//------------------------------------------------
void Reverberation::setParameter3(float input)
{
}
float Reverberation::getParameter3() const
{
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
    
}
