//
//  PedalGUI.cpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "PedalGUI.hpp"



PedalGUI::PedalGUI()
{
    onOffButton.setColour (TextButton::buttonColourId, Colours::grey);
    onOffButton.setColour (TextButton::buttonOnColourId, Colours::lightgrey);
    addAndMakeVisible(&onOffButton);
    onOffButton.addListener(this);
    
    parameterSlider1.setSliderStyle(Slider::Rotary);
    addAndMakeVisible(&parameterSlider1);
    parameterSlider1.addListener(this);
    
    parameterSlider2.setSliderStyle(Slider::Rotary);
    addAndMakeVisible(&parameterSlider2);
    parameterSlider2.addListener(this);
    
    parameterSlider2.setSliderStyle(Slider::Rotary);
    addAndMakeVisible(&parameterSlider3);
    parameterSlider3.addListener(this);
    
}

PedalGUI::~PedalGUI()
{
    
}

void PedalGUI::setPedal(Pedal* pedalPtr)
{
    pedal = pedalPtr;
}

void PedalGUI::resized()
{
    auto r = getLocalBounds();
    auto row = r.removeFromTop (getHeight() / 3);
    auto row2 = r.removeFromTop(getHeight() / 2);
    onOffButton.setBounds (row.removeFromLeft (getWidth() / 4));
}

void PedalGUI::buttonClicked(Button *button)
{
    if (pedal == nullptr)
        return;
    
    if (button == &onOffButton)
    {
        pedal->setOnOffState( ! pedal->isOn());
        onOffButton.setToggleState(pedal->isOn(), dontSendNotification);
        if (pedal->isOn())
            onOffButton.setButtonText ("Pedal is On");
        else
            onOffButton.setButtonText("Pedal is Off");
    }
}

void PedalGUI::sliderValueChanged (Slider* slider)
{
    if (slider == &parameterSlider1)
        pedal->setParameter1(parameterSlider1.getValue());
    else if (slider == &parameterSlider2)
        pedal->setParameter2(parameterSlider2.getValue());
    else if (slider == &parameterSlider3)
        pedal->setParameter3(parameterSlider3.getValue());
}
