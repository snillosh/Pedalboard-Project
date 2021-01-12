//
//  PedalGUI.hpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"

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
    
private:
    Pedal* pedal           {nullptr};
    TextButton onOffButton {"On"};
    Slider parameterSlider1;
    Slider parameterSlider2;
    Slider parameterSlider3;
    
    
};

