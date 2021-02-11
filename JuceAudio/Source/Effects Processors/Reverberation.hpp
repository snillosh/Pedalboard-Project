/*
  ==============================================================================

    Reverb.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Pedal.hpp"


/** A simple reverb created using 3 delays with very short delay times and feedback, then processed using a lowpass filter.This audio effect is controled using: filter cutoff (parameter2), feedback gain (parameter3). */
class Reverberation : public Pedal
{
public:
    /** Reverberation constructer*/
    Reverberation();
    /** Reverberation destructor */
    ~Reverberation();
    
    /** Initialises the variables and audio buffer*/
    void initialise ();
    
    /** updates the lowpass filter within the audio callback function*/
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
    float cutOff, feedbackGain, delayTime1, delayTime2, delayTime3, delayTimeParameter;
    float sampleRate = 44100.0f;
    
    float *pfCircularBuffer;
    int iBufferSize;
    int iBufferWritePos;
    
    int iBufferReadPos1;
    int iBufferReadPos2;
    int iBufferReadPos3;
    
    float fDelSig1 = 0;
    float fDelSig2 = 0;
    float fDelSig3 = 0;
    float fDelSigSummed = 0;
    
    float fOut;
    
    //Creates an array of lowpass filters
    OwnedArray<juce::dsp::FirstOrderTPTFilter<float>> lowPassFilter;
    
};
