/*
  ==============================================================================

    Pedal.cpp
    Created: 09 Jan 2021 4:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Pedal.hpp"

Pedal::Pedal()
{
    
}

Pedal::~Pedal()
{
    
}

void Pedal::setOnOffState(const bool newState)
{
    onOffState = newState;
}

bool Pedal::isOn() const
{
    return onOffState.load();
}
