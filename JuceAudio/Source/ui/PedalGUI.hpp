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
    void buttonClicked (Button* button) override;
    void sliderValueChanged (Slider* slider) override;
    void updateParametes(Pedal* pedal);
    
private:
    Pedal* pedal           {nullptr};
    Audio* audio           {nullptr};
    TextButton onOffButton {"Pedal is Off"};
    Slider parameterSlider1;
    Label parameterSlider1Label;
    Slider parameterSlider2;
    Label parameterSlider2Label;
    Slider parameterSlider3;
    Slider parameterSlider4;
    Slider parameterSlider5;
};

