/*
  ==============================================================================

    Compressor.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/LFO.h"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Pedal.hpp"


/**A simple LFO tremolo where the volume of  the input signal is modulated by a sine wave LFO.This audio effect is controled using the standard tremolo controls: depth (parameter2) and rate (parameter3).*/
class Tremolo :   public Pedal
{
public:
    Tremolo();
    ~Tremolo();
    
    /** Initialises the variables and the LFO for tremolo*/
    void intitialise();
    
    /** Updates the LFO so variables update within the audio callback function*/
    void updateLFO();
    
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
    
    /** Returns processed audio siganl from the pedal effect
     @return output value of the pedal
     @param input input value to the pedal*/
    float process(float input) override;
    
private:

    float rate, depth;
    float sampleRate = 44100.0f;
    
    LFO LFO;
};
