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
    parameterSlider1.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    addAndMakeVisible(&parameterSlider1);
    parameterSlider1.addListener(this);
    parameterSlider1Label.attachToComponent(&parameterSlider1, false);
    
    addAndMakeVisible(parameterSlider1Label);

    parameterSlider2.setSliderStyle(Slider::Rotary);
    parameterSlider2.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    addAndMakeVisible(&parameterSlider2);
    parameterSlider2.addListener(this);
    
    parameterSlider2Label.attachToComponent(&parameterSlider2, false);
    addAndMakeVisible(parameterSlider2Label);
    
    parameterSlider3.setSliderStyle(Slider::Rotary);
    parameterSlider3.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    addAndMakeVisible(&parameterSlider3);
    parameterSlider3.addListener(this);
    
    parameterSlider4.setSliderStyle(Slider::Rotary);
    parameterSlider4.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    addAndMakeVisible(&parameterSlider4);
    parameterSlider4.addListener(this);
    
    parameterSlider5.setSliderStyle(Slider::Rotary);
    parameterSlider5.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
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
    auto r = getLocalBounds();
    auto row = r.removeFromTop((getHeight() / 8) * 7);
    auto row2 = r.removeFromBottom(getHeight() / 8);
    onOffButton.setBounds (row2.removeFromLeft (getWidth()));
    parameterSlider1.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider2.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider3.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider4.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider5.setBounds(row.removeFromBottom(getHeight() / 6));

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

void PedalGUI::updateParametes(Pedal *delay, Pedal *phaser, Pedal *compressor, Pedal *reverberation, Pedal *none)
{
    if (pedal == delay)
    {
        parameterSlider1Label.setText("Feedback Gain", dontSendNotification);
        parameterSlider2Label.setText("Delay Time", dontSendNotification);
        parameterSlider1.setVisible(true);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(false);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
    if (pedal == compressor)
    {
        parameterSlider1Label.setText("Attack", dontSendNotification);
        parameterSlider2Label.setText("Release", dontSendNotification);
        parameterSlider1.setVisible(true);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
    if (pedal == reverberation)
    {
        parameterSlider1Label.setText("Size", dontSendNotification);
        parameterSlider2Label.setText("Mix", dontSendNotification);
        parameterSlider1.setVisible(true);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(true);
        parameterSlider5.setVisible(false);
    }
    if (pedal == phaser)
    {
        parameterSlider1Label.setText("Rate", dontSendNotification);
        parameterSlider2Label.setText("Depth", dontSendNotification);
        parameterSlider1.setVisible(true);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(true);
        parameterSlider5.setVisible(true);
    }
    else if (pedal == none)
    {
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText(" ", dontSendNotification);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(false);
        parameterSlider3.setVisible(false);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
}
