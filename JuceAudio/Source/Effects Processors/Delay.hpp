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


/**A simple audio buffer based delay with feedback.This audio effect is controled using the standard delay controls: delay time (parameter2) and feedback volume (parameter3).*/
class Delay : public Pedal
{
public:
    /** Delay constructor*/
    Delay();
    
    /**Delay destructor*/
    ~Delay();
    
    /** Initalises the variables and buffer uses in delay*/
    void initialise ();
    
    /** Sets the pedal effect parameter value to the value of parameterSlider1 in the pedalGUI class
     @param input the input from parameterSlider1 to the pedal effect
     @see getParameter1*/
    void setParameter1(float input) override;
    
    /** Returns the parameter1 value stored within the pedal effect
     @return parameter1 float value
     @see setParameter1*/
    float getParameter1() const override;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider2 in the pedalGUI class
     @param input the input from parameterSlider2 to the pedal effect
     @see getParameter2*/
    void setParameter2(float input) override;
    
    /** Returns the parameter2 value stored within the pedal effect
     @return parameter2 float value
     @see setParameter2*/
    float getParameter2() const override;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider3 in the pedalGUI class
     @param input the input from parameterSlider3 to the pedal effect
     @see getParameter3*/
    void setParameter3(float input) override;
    
    /** Returns the parameter3 value stored within the pedal effect
     @return parameter3 float value
     @see setParameter3*/
    float getParameter3() const override;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider4 in the pedalGUI class
     @param input the input from parameterSlider4 to the pedal effect
     @see getParameter4*/
    void setParameter4(float input) override;
    
    /** Returns the parameter4 value stored within the pedal effect
     @return parameter4 float value
     @see setParameter4*/
    float getParameter4() const override;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider5 in the pedalGUI class
     @param input the input from parameterSlider5 to the pedal effect
     @see getParameter5*/
    void setParameter5(float input) override;
    
    /** Returns the parameter5 value stored within the pedal effect
     @return parameter5 float value
     @see setParameter5*/
    float getParameter5() const override;
    
    /** Returns processed audio siganl from the pedal effect
     @return output value of the pedal
     @param input input value to the pedal*/
    float process(float input) override;

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
