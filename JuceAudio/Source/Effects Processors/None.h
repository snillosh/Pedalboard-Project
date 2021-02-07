/*
  ==============================================================================

    None.h
    Created: 7 Feb 2021 11:00:42pm
    Author:  Bevan Salter

  ==============================================================================
*/
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"
#pragma once


class None : public Pedal
{
public:
    None();
    ~None();
    
    void intitialise();
    
    float process(float input) override;
    
    float Compress(float x);
    
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
private:
    
};
