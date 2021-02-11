/*
  ==============================================================================

    None.h
    Created: 7 Feb 2021 11:00:42pm
    Author:  Bevan Salter

  ==============================================================================
*/
#include "Pedal.hpp"
#pragma once

/** Blank pedal class to set the audio and GUI to an empty state*/
class BlankPedal : public Pedal
{
public:
    /**BlankPedal Constructor*/
    BlankPedal();
    /**BlankPedal destructor*/
    ~BlankPedal();
    
    //functions from base pedal class that have been overriden
    
    void setParameter1(float input) override;
    
    float getParameter1() const override;
    
    void setParameter2(float input) override;
    
    float getParameter2() const override;
    
    void setParameter3(float input) override;
    
    float getParameter3() const override;
    
    void setParameter4(float input) override;
    
    float getParameter4() const override;
    
    void setParameter5(float input) override;
    
    float getParameter5() const override;
    
    float process(float input) override;
    
private:
    
};
