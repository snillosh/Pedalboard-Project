//
//  Pedal.hpp
//  Practical 7 2021 - App
//
//  Created by Bevan Salter on 09/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include <JuceHeader.h>

class Pedal
{
public:
    Pedal();
    ~Pedal();
    
    bool getPedalState();
    void setPedalState(bool onOrOff);
    
private:
    bool pedalState = false;
};
