/*
  ==============================================================================

    RecordComponent.cpp
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LooperGUI.h"

//==============================================================================
LooperGUI::LooperGUI()
{
    playButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    playButton.setColour (TextButton::buttonColourId, Colours::green);
    playButton.setColour (TextButton::buttonOnColourId, Colours::darkgreen);
    addAndMakeVisible (&playButton);
    playButton.addListener (this);
    
    recordButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    recordButton.setColour (TextButton::buttonColourId, Colours::red);
    recordButton.setColour (TextButton::buttonOnColourId, Colours::darkred);
    addAndMakeVisible (&recordButton);
    recordButton.addListener (this);
    
    saveButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    saveButton.setColour (TextButton::buttonColourId, Colours::blue);
    saveButton.setColour (TextButton::buttonOnColourId, Colours::darkblue);
    addAndMakeVisible (&saveButton);
    saveButton.addListener (this);
    
    resetButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    resetButton.setColour (TextButton::buttonColourId, Colours::orange);
    resetButton.setColour (TextButton::buttonOnColourId, Colours::darkorange);
    addAndMakeVisible (&resetButton);
    saveButton.addListener (this);
}

LooperGUI::~LooperGUI()
{
}

void LooperGUI::paint (juce::Graphics& g)
{
}

void LooperGUI::resized()
{
    auto r = getLocalBounds();
    auto row = r.removeFromTop (getHeight());
    playButton.setBounds (row.removeFromLeft (getWidth() / 4));
    recordButton.setBounds (row.removeFromLeft(getWidth() / 4));
    saveButton.setBounds ( row.removeFromLeft(getWidth() / 4));
    resetButton.setBounds (row.removeFromLeft(getWidth() / 4));
}

void LooperGUI::buttonClicked(Button* button)
{
    if (looper == nullptr)
        return;
    
    if (button == &playButton)
    {
        looper->setPlayState( ! looper->isPlaying());
        playButton.setToggleState ( looper->isPlaying(), dontSendNotification);
        if (looper->isPlaying())
            playButton.setButtonText("Stop");
        else
            playButton.setButtonText("Play");
    }
    if ( button == &recordButton)
    {
        looper->setRecordState( ! looper->isRecording());
        recordButton.setToggleState(looper->isRecording(), dontSendNotification);
    }
    if ( button == &resetButton)
    {
        DBG("RESET BUTTON CLICKED");
        looper->reset();
    }
}

void LooperGUI::setLooper(Looper *newLooper)
{
    looper = newLooper;
}
