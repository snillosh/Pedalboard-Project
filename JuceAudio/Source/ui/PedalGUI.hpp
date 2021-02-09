/*
  ==============================================================================

    PedalGUI.hpp
    Created: 12 Jan 2021 8:30:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Audio.h"

class PedalGUI : public Component,
                 public Button::Listener,
                 public Slider::Listener
{
public:
    PedalGUI();
    ~PedalGUI();
    
    void setPedal (Pedal* pedalPtr);
    void resized() override;
    void paint (juce::Graphics&) override;
    
    void buttonClicked (Button* button) override;
    void sliderValueChanged (Slider* slider) override;
    void updateParametes(Pedal* delay, Pedal* phaser, Pedal* tremolo, Pedal* reverberation, Pedal* none);
    void resetButton();
    
    void setPedalColour(int colour);
    
private:
    Pedal* pedal           {nullptr};
    
    int pedalColour;
    LookAndFeel_V4 otherLookAndFeel;
    TextButton onOffButton {"Pedal is Off"};
    
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

