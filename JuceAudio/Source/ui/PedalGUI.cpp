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
    
    //onOffButton Config
    //-------------------------------------------------------------------------
    onOffButton.setColour (TextButton::buttonColourId, Colours::grey);
    onOffButton.setColour (TextButton::buttonOnColourId, Colours::lightgrey);
    addAndMakeVisible(&onOffButton);
    onOffButton.addListener(this);
    //Slider 1 Config
    //-------------------------------------------------------------------------
    parameterSlider1.setSliderStyle(Slider::Rotary);
    parameterSlider1.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    otherLookAndFeel.setColour (juce::Slider::thumbColourId, juce::Colours::red);
    parameterSlider1.setLookAndFeel (&otherLookAndFeel);
    addAndMakeVisible(&parameterSlider1);
    parameterSlider1.addListener(this);
    //Slider 1 Label Config
    //-------------------------------------------------------------------------
    parameterSlider1Label.attachToComponent(&parameterSlider1, false);
    parameterSlider1Label.setColour(TextEditor::textColourId, Colours::black);
    addAndMakeVisible(parameterSlider1Label);
    //Slider 2 Config
    //-------------------------------------------------------------------------
    parameterSlider2.setSliderStyle(Slider::Rotary);
    parameterSlider2.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    otherLookAndFeel.setColour (juce::Slider::thumbColourId, juce::Colours::green);
    parameterSlider2.setLookAndFeel (&otherLookAndFeel);
    addAndMakeVisible(&parameterSlider2);
    parameterSlider2.addListener(this);
    //Slider 2 Label Config
    //-------------------------------------------------------------------------
    parameterSlider2Label.attachToComponent(&parameterSlider2, false);
    addAndMakeVisible(parameterSlider2Label);
    //Slider 3 Config
    //-------------------------------------------------------------------------
    parameterSlider3.setSliderStyle(Slider::Rotary);
    parameterSlider3.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    otherLookAndFeel.setColour (juce::Slider::thumbColourId, juce::Colours::blue);
    parameterSlider3.setLookAndFeel (&otherLookAndFeel);
    addAndMakeVisible(&parameterSlider3);
    parameterSlider3.addListener(this);
    //Slider 3 Label Config
    //-------------------------------------------------------------------------
    parameterSlider3Label.attachToComponent(&parameterSlider3, false);
    addAndMakeVisible(parameterSlider3Label);
    //Slider 4 Config
    //-------------------------------------------------------------------------
    parameterSlider4.setSliderStyle(Slider::Rotary);
    parameterSlider4.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    otherLookAndFeel.setColour (juce::Slider::thumbColourId, juce::Colours::yellow);
    parameterSlider4.setLookAndFeel (&otherLookAndFeel);
    addAndMakeVisible(&parameterSlider4);
    parameterSlider4.addListener(this);
    //Slider 4 Label Config
    //-------------------------------------------------------------------------
    parameterSlider4Label.attachToComponent(&parameterSlider4, false);
    addAndMakeVisible(parameterSlider4Label);
    //Slider 5 Config
    //-------------------------------------------------------------------------
    parameterSlider5.setSliderStyle(Slider::Rotary);
    parameterSlider5.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    otherLookAndFeel.setColour (juce::Slider::thumbColourId, juce::Colours::silver);
    otherLookAndFeel.setColour (juce::Slider::trackColourId, juce::Colours::transparentBlack);
    parameterSlider5.setLookAndFeel (&otherLookAndFeel);
    addAndMakeVisible(&parameterSlider5);
    parameterSlider5.addListener(this);
    //Slider 5 Label Config
    //-------------------------------------------------------------------------
    parameterSlider5Label.attachToComponent(&parameterSlider5, false);
    addAndMakeVisible(parameterSlider5Label);
    //-------------------------------------------------------------------------
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
    onOffButton.setBounds(getWidth() / 4, getHeight() * 0.7, getWidth() * 0.5, getHeight() * 0.15);
    parameterSlider1.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider2.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider3.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider4.setBounds(row.removeFromBottom(getHeight() / 6));
    parameterSlider5.setBounds(row.removeFromBottom(getHeight() / 6));

}

void PedalGUI::paint(juce::Graphics &g)
{
    if (pedalColour == 0)
    {
        g.setColour(Colours::transparentBlack);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::transparentBlack);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
    }
    if (pedalColour == 1)
    {
        g.setColour(Colours::purple);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
    }
    if (pedalColour == 2)
    {
        g.setColour(Colours::green);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
    }
    if (pedalColour == 3)
    {
        g.setColour(Colours::blue);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
    }
    if (pedalColour == 4)
    {
        g.setColour(Colours::orangered);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
    }
    
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
        setPedalColour(1);
        repaint();
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText("Delay Time", dontSendNotification);
        parameterSlider3Label.setText("Feedback Gain", dontSendNotification);
        parameterSlider4Label.setText(" ", dontSendNotification);
        parameterSlider5Label.setText(" ", dontSendNotification);
        
        onOffButton.setVisible(true);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
    if (pedal == compressor)
    {
        setPedalColour(2);
        repaint();
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText("Depth", dontSendNotification);
        parameterSlider3Label.setText("Rate", dontSendNotification);
        parameterSlider4Label.setText(" ", dontSendNotification);
        parameterSlider5Label.setText(" ", dontSendNotification);
        
        onOffButton.setVisible(true);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
    if (pedal == reverberation)
    {
        setPedalColour(3);
        repaint();
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText("Cutoff", dontSendNotification);
        parameterSlider3Label.setText("Reverb Amount", dontSendNotification);
        parameterSlider4Label.setText(" ", dontSendNotification);
        parameterSlider5Label.setText(" ", dontSendNotification);
        
        onOffButton.setVisible(true);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
    if (pedal == phaser)
    {
        setPedalColour(4);
        repaint();
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText("Depth", dontSendNotification);
        parameterSlider3Label.setText("Feedback", dontSendNotification);
        parameterSlider4Label.setText("Mix", dontSendNotification);
        parameterSlider5Label.setText("Rate", dontSendNotification);
        
        onOffButton.setVisible(true);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(true);
        parameterSlider5.setVisible(true);
    }
    else if (pedal == none)
    {
        setPedalColour(0);
        repaint();
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText(" ", dontSendNotification);
        parameterSlider3Label.setText(" ", dontSendNotification);
        parameterSlider4Label.setText(" ", dontSendNotification);
        parameterSlider5Label.setText(" ", dontSendNotification);
        
        onOffButton.setVisible(false);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(false);
        parameterSlider3.setVisible(false);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);
    }
}

void PedalGUI::resetButton()
{
    pedal->setOnOffState(false);
}


void PedalGUI::setPedalColour(int colour)
{
    pedalColour = colour;
}
