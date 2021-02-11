/*
  ==============================================================================

    Pedal.hpp
    Created: 09 Jan 2021 4:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

/** Abstract base pedal class for the effects processors*/
class Pedal
{
public:
    /** Pedal constructor*/
    Pedal();
    
    /** Pedal destructor */
    virtual ~Pedal();
    
    /** Sets the pedal to on or off
     @param newState sets state to true for on or false for off
     @see isOn() */
    virtual void setOnOffState (bool newState);
    
    /**Returns the on off state
     @return the on off state
     @see setOnOffState */
    bool isOn() const;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider1 in the pedalGUI class
     @param input the input from parameterSlider1 to the pedal effect
     @see getParameter1*/
    virtual void setParameter1(float input) = 0;
    
    /** Returns the parameter1 value stored within the pedal effect
     @return parameter1 float value
     @see setParameter1*/
    virtual float getParameter1() const = 0;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider2 in the pedalGUI class
     @param input the input from parameterSlider2 to the pedal effect
     @see getParameter2*/
    virtual void setParameter2(float input) = 0;
    
    /** Returns the parameter2 value stored within the pedal effect
     @return parameter2 float value
     @see setParameter2*/
    virtual float getParameter2() const = 0;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider3 in the pedalGUI class
     @param input the input from parameterSlider3 to the pedal effect
     @see getParameter3*/
    virtual void setParameter3(float input) = 0;
    
    /** Returns the parameter3 value stored within the pedal effect
     @return parameter3 float value
     @see setParameter3*/
    virtual float getParameter3 () const = 0;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider4 in the pedalGUI class
     @param input the input from parameterSlider4 to the pedal effect
     @see getParameter4*/
    virtual void setParameter4(float input) = 0;
    
    /** Returns the parameter4 value stored within the pedal effect
     @return parameter4 float value
     @see setParameter4*/
    virtual float getParameter4 () const = 0;
    
    /** Sets the pedal effect parameter value to the value of parameterSlider5 in the pedalGUI class
     @param input the input from parameterSlider5 to the pedal effect
     @see getParameter5*/
    virtual void setParameter5(float input) = 0;
    
    /** Returns the parameter5 value stored within the pedal effect
     @return parameter5 float value
     @see setParameter5*/
    virtual float getParameter5 () const = 0;
    
    /** Returns processed audio siganl from the pedal effect
     @return output value of the pedal
     @param input input value to the pedal*/
    virtual float process(float input) = 0;
    
    
private:
    /** Atomic int for the on off state of the pedal*/
    std::atomic<int> onOffState   {false};
};
