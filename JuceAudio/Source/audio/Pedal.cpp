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

bool Pedal::getPedalState()
{
    return pedalState;
}

void Pedal::setPedalState(bool onOrOff)
{
    pedalState = onOrOff;
}
