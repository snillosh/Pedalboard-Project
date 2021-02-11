/*
  ==============================================================================

    Phaser.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/
#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Pedal.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/LFO.h"
/**A 6 stage phaser that modulates first order all-pass filters to create sweeping notches in the magnitude frequency response.This audio effect is controled using the standard phaser controls: depth (parameter2), feedback (parameter3) and rate (parameter4).*/
class Phaser : public Pedal
{
public:
    /** Phaser constructor*/
    Phaser();
    /**Phaser destructor*/
    ~Phaser();
    
    /** Initialises the variables and filters for use in the phaser*/
    void initialise();
    
    /** Updates the LFO and filters within the audio callback function*/
    void updateFilter();
    
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
    OwnedArray<juce::dsp::FirstOrderTPTFilter<float>> allpassFilters; //Sets up an array of JUCE allpass filters
    
    LFO rateLFO;
    
    float depth, feedback, mix, output;
    float rate;
    static constexpr int numStages = 6;
    float sampleRate = 44100.0f;
    float allpassOutFinal = 1.0f;
};
