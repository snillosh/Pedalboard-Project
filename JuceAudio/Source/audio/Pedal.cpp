//
//  Pedal.cpp
//  Practical 7 2021 - App
//
//  Created by Bevan Salter on 09/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

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

void Pedal::setParameter1(float input)
{
    
}

void Pedal::setParameter2(float input)
{
    
}

void Pedal::setParameter3(float input)
{
    
}
