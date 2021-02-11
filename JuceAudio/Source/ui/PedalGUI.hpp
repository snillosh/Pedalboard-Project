/*
  ==============================================================================

    PedalGUI.hpp
    Created: 12 Jan 2021 8:30:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Pedal.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Audio.h"

/** PedalGUI class for displaying the sliders, buttons, labels and graphics with main component.
 Used in a vector to create multiple*/
class PedalGUI : public Component,
                 public Button::Listener,
                 public Slider::Listener
{
public:
    /** PedalGUI Constructor*/
    PedalGUI();
    /** PedalGUI Destructor*/
    ~PedalGUI();
    
    /** Sets pedalGUI pedal pointer to the corresponding audio pedal
     @param pedalPtr pointer to set*/
    void setGUIPedal (Pedal* pedalPtr);
    
    /** Returns pedalGUI pedal pointer
     @return pedal pointer*/
    Pedal* getGUIPedal() const;
    
    void resized() override;
    
    void paint (juce::Graphics&) override;
    
    void buttonClicked (Button* button) override;
    
    void sliderValueChanged (Slider* slider) override;
    /** Updates the look of the pedalGUI object depending on what pedal is in the slot
     @param delay the reference to delay object
     @param phaser the reference to phaser object
     @param tremolo the reference to tremolo object
     @param reverberation the reference to reverberation object
     @param blankPedal the reference to the blank pedal object*/
    void updateGUIParameters(Pedal* delay, Pedal* phaser, Pedal* tremolo, Pedal* reverberation, Pedal* blankPedal);
    
    /** Sets the paint colour for the different effect types depending on which one is in the slot
     @param colour set the differnt colour (1-5)*/
    void setPedalColour(int colour);
    
private:
    Pedal* pedal           {nullptr}; // pointer to pedal
    
    int pedalColour;
    LookAndFeel_V4 otherLookAndFeel;
    
    TextButton onOffButton;
    
    Slider parameterSlider1;
    Slider parameterSlider2;
    Slider parameterSlider3;
    Slider parameterSlider4;
    Slider parameterSlider5;
    
    Label parameterSlider1Label;
    Label parameterSlider2Label;
    Label parameterSlider3Label;
    Label parameterSlider4Label;
    Label parameterSlider5Label;
};

