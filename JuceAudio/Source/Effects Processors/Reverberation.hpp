/*
  ==============================================================================

    Reverb.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"

class Reverberation : public Pedal
{
public:
    Reverberation();
    ~Reverberation();
    
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
    
    void initialise ();
    
    void updateFilter();
    
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
    
    OwnedArray<juce::dsp::FirstOrderTPTFilter<float>> lowPassFilter;
    
};
