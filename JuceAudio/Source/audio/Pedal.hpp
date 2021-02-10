/*
  ==============================================================================

    Pedal.hpp
    Created: 09 Jan 2021 4:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
// Base class for each effect processor. 
class Pedal
{
public:
    Pedal();
    virtual ~Pedal();
    
    virtual void setOnOffState (bool newState);
    bool isOn() const;
    
    virtual void setParameter1(float input) = 0;
    virtual float getParameter1() const = 0;
    
    virtual void setParameter2(float input) = 0;
    virtual float getParameter2() const = 0;
    
    virtual void setParameter3(float input) = 0;
    virtual float getParameter3 () const = 0;
    
    virtual void setParameter4(float input) = 0;
    virtual float getParameter4 () const = 0;
    
    virtual void setParameter5(float input) = 0;
    virtual float getParameter5 () const = 0;
    
    virtual float process(float input) = 0;
    
    
private:
    std::atomic<int> onOffState   {false};
};
