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
    virtual ~Pedal();
    
    virtual void setOnOffState (bool newState);
    bool isOn() const;
    
    void setEnabled(bool newState);
    bool isEnabled() const;
    
    virtual void setParameter1(float input) = 0;
    float getParameter1() const;
    
    virtual void setParameter2(float input) = 0;
    float getParameter2() const;
    
    virtual void setParameter3(float input) = 0;
    float getParameter3 () const;
    
    virtual void setParameter4(float input) = 0;
    float getParameter4 () const;
    
    virtual void setParameter5(float input) = 0;
    float getParameter5 () const;
    
    virtual float process(float input) = 0;
    
    
private:
    std::atomic<int> onOffState   {false};
    std::atomic<int> EnabledState    {false};
    float parameter1 = 0;
    float parameter2 = 0;
    float parameter3 = 0;
    float parameter4 = 0;
    float parameter5 = 0;
};
