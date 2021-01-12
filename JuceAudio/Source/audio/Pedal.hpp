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
    float getParameter1() const;
    void setParameter2(float input);
    float getParameter2() const;
    void setParameter3(float input);
    float getParameter3 () const;
    
private:
    std::atomic<int> onOffState   {false};
    float parameter1 = 0;
    float parameter2 = 0;
    float parameter3 = 0;
};
