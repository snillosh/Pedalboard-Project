/*
  ==============================================================================

    Delay.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"
/**
    A simple audio buffer based delay with feedback.

    This audio effect is controled using the standard delay controls: delay time (parameter2) and feedback volume (parameter3).
*/
class Delay : public Pedal
{
public:
    Delay();
    ~Delay();
    
    
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

private:
    float *pfCircularBuffer;
    float fSR;
    int iBufferSize;
    int iBufferWritePos;
    int iBufferReadPos;
    float fDelSig = 0;
    float fFeedbackGain;
    float fDelayTime;
    float fOut;
};
