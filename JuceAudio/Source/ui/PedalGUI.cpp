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
    //set default pedal Gui looks
    
    //onOffButton Config
    //-------------------------------------------------------------------------
    onOffButton.setColour (TextButton::buttonColourId, Colours::grey);
    onOffButton.setColour (TextButton::buttonOnColourId, Colours::darkgrey);
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
    parameterSlider1Label.attachToComponent(&parameterSlider1, true);
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
    parameterSlider2Label.attachToComponent(&parameterSlider2, true);
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
    parameterSlider3Label.attachToComponent(&parameterSlider3, true);
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
    parameterSlider4Label.attachToComponent(&parameterSlider4, true);
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
    parameterSlider5Label.attachToComponent(&parameterSlider5, true);
    addAndMakeVisible(parameterSlider5Label);
    //-------------------------------------------------------------------------
}

PedalGUI::~PedalGUI()
{
}

void PedalGUI::setGUIPedal(Pedal* pedalPtr)
{
    pedal = pedalPtr;
}

void PedalGUI::resized()
{
    onOffButton.setBounds(getWidth() / 4, getHeight() * 0.7, getWidth() * 0.25, getHeight() * 0.10);
    
    parameterSlider1.setBounds(getWidth() / 3, getHeight() / 6, getWidth() / 3, getWidth() / 3);
    parameterSlider2.setBounds(getWidth() / 3, ((getHeight() / 48)), 100, 100);
    parameterSlider3.setBounds(getWidth() / 3, ((getHeight() / 6) ), 100, 100);
    parameterSlider4.setBounds(getWidth() / 3, ((getHeight() / 6) * 2), 100, 100);
    parameterSlider5.setBounds(getWidth() / 3, ((getHeight() / 6) * 3), 100, 100);
}

void PedalGUI::paint(juce::Graphics &g)
{
    if (pedalColour == 0) // if blankPedal is selected
    {
        g.setColour(Colours::transparentBlack);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::transparentBlack);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
        g.setColour(Colours::transparentBlack);
        g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
    }
    if (pedalColour == 1) // if delay is selected
    {
        g.setColour(Colours::purple);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
        g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        if (pedal->isOn())
        {
            g.setColour(Colours::red);
            g.fillEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25);
            g.setColour(Colours::black);
            g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        }
    }
    if (pedalColour == 2) // if tremolo is selected
    {
        g.setColour(Colours::green);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
        g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        if (pedal->isOn())
        {
            g.setColour(Colours::red);
            g.fillEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25);
            g.setColour(Colours::black);
            g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        }
    }
    if (pedalColour == 3) // if reverb is selected
    {
        g.setColour(Colours::blue);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
        g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        if (pedal->isOn())
        {
            g.setColour(Colours::red);
            g.fillEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25);
            g.setColour(Colours::black);
            g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        }
    }
    if (pedalColour == 4) // if phaser is selected
    {
        g.setColour(Colours::orange);
        g.fillRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5);
        g.setColour(Colours::black);
        g.drawRoundedRectangle(getWidth() * 0.1, getHeight() * 0.025, getWidth() * 0.8, getHeight() * 0.835, 5, 5);
        g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        if (pedal->isOn())
        {
            g.setColour(Colours::red);
            g.fillEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25);
            g.setColour(Colours::black);
            g.drawEllipse(getWidth() * 0.65, getHeight() * 0.72, 25, 25, 5);
        }
    }
    
}

void PedalGUI::buttonClicked(Button *button)
{
    if (button == &onOffButton)
    {
        pedal->setOnOffState( ! pedal->isOn());
        onOffButton.setToggleState(pedal->isOn(), dontSendNotification);
        if (pedal->isOn())
        {
            repaint(); // repaint when button is clicked
        }
            
        else
        {
            repaint();
        }
            
    }
}

void PedalGUI::sliderValueChanged (Slider* slider)
{
    if (slider == &parameterSlider1)
        pedal->setParameter1(parameterSlider1.getValue()); // send slider values to effect
    else if (slider == &parameterSlider2)
        pedal->setParameter2(parameterSlider2.getValue());
    else if (slider == &parameterSlider3)
        pedal->setParameter3(parameterSlider3.getValue());
    else if (slider == &parameterSlider4)
        pedal->setParameter4(parameterSlider4.getValue());
    else if (slider == &parameterSlider3)
        pedal->setParameter5(parameterSlider5.getValue());
}

void PedalGUI::updateGUIParameters(Pedal *delay, Pedal *phaser, Pedal *tremolo, Pedal *reverberation, Pedal *blankPedal)
{
    if (pedal == delay) // if the reference that pedal Gui is the same as the reference for delay in audio
    {
        setPedalColour(1); // set the colours to change
        repaint();
        parameterSlider1Label.setText(" ", dontSendNotification);
        parameterSlider2Label.setText("Time", dontSendNotification);  // change labels
        parameterSlider3Label.setText("Feedback", dontSendNotification);
        parameterSlider4Label.setText(" ", dontSendNotification);
        parameterSlider5Label.setText(" ", dontSendNotification);
        
        onOffButton.setVisible(true);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(false);
        parameterSlider5.setVisible(false);  // make certain sliders invisible
    }
    if (pedal == tremolo)
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
        parameterSlider3Label.setText("Amount", dontSendNotification);
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
        parameterSlider4Label.setText("Rate", dontSendNotification);
        parameterSlider5Label.setText(" ", dontSendNotification);
        
        onOffButton.setVisible(true);
        parameterSlider1.setVisible(false);
        parameterSlider2.setVisible(true);
        parameterSlider3.setVisible(true);
        parameterSlider4.setVisible(true);
        parameterSlider5.setVisible(false);
    }
    else if (pedal == blankPedal)
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

void PedalGUI::setPedalColour(int colour)
{
    pedalColour = colour;
}
