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

void Pedal::setEnabled(bool newState)
{
    EnabledState = newState;
}

bool Pedal::isEnabled() const
{
    return EnabledState;
}

void Pedal::setParameter1(float input)
{
    parameter1 = input;
}

float Pedal::getParameter1() const
{
    return parameter1;
}

void Pedal::setParameter2(float input)
{
    parameter2 = input;
}

float Pedal::getParameter2() const
{
    return parameter2;
}

void Pedal::setParameter3(float input)
{
    parameter3 = input;
}

float Pedal::getParameter3() const
{
    return parameter3;
}

void Pedal::setParameter4(float input)
{
    parameter4 = input;
}

float Pedal::getParameter4() const
{
    return parameter4;
}

void Pedal::setParameter5(float input)
{
    parameter5 = input;
}

float Pedal::getParameter5() const
{
    return parameter5;
}

float Pedal::process(float input)
{
    return input;
}
