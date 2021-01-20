/*
  ==============================================================================

    Phaser.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/
#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"

class Phaser : public Pedal
{
public:
    Phaser();
    ~Phaser();
    
    float process(float input) override;
    
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
