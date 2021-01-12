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
    
    void setOnOffState (bool newState);
    bool isOn() const;
    void setParameter1(float input);
    void setParameter2(float input);
    void setParameter3(float input);
    
private:
    std::atomic<int> onOffState   {false};
};
