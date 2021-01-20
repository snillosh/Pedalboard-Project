/*
  ==============================================================================

    PedalGUI.cpp
    Created: 12 Jan 2021 8:30:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

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
    
    parameterSlider3.setSliderStyle(Slider::Rotary);
    addAndMakeVisible(&parameterSlider3);
    parameterSlider3.addListener(this);
    
    parameterSlider4.setSliderStyle(Slider::Rotary);
    addAndMakeVisible(&parameterSlider4);
    parameterSlider4.addListener(this);
    
    parameterSlider5.setSliderStyle(Slider::Rotary);
    addAndMakeVisible(&parameterSlider5);
    parameterSlider5.addListener(this);
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
    //auto r2 = getLocalBounds();
    auto r = getLocalBounds();
    auto row = r.removeFromTop((getHeight() / 8) * 7);
    auto row2 = r.removeFromBottom(getHeight() / 8);
    onOffButton.setBounds (row2.removeFromLeft (getWidth()));
    parameterSlider1.setBounds(row.removeFromBottom(getHeight() / 8));
    parameterSlider2.setBounds(row.removeFromBottom(getHeight() / 8));
    parameterSlider3.setBounds(row.removeFromBottom(getHeight() / 8));
    parameterSlider4.setBounds(row.removeFromBottom(getHeight() / 8));
    parameterSlider5.setBounds(row.removeFromBottom(getHeight() / 8));
}

void PedalGUI::buttonClicked(Button *button)
{
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
    else if (slider == &parameterSlider4)
        pedal->setParameter4(parameterSlider4.getValue());
    else if (slider == &parameterSlider3)
        pedal->setParameter5(parameterSlider5.getValue());
}
