/*
  ==============================================================================

    RecordComponent.cpp
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RecordComponent.h"

//==============================================================================
RecordComponent::RecordComponent()
{
    playButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    playButton.setColour (TextButton::buttonColourId, Colours::lightblue);
    playButton.setColour (TextButton::buttonOnColourId, Colours::lightgrey);
    addAndMakeVisible (&playButton);
    playButton.addListener (this);
    
    recordButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    recordButton.setColour (TextButton::buttonColourId, Colours::goldenrod);
    recordButton.setColour (TextButton::buttonOnColourId, Colours::lightgrey);
    addAndMakeVisible (&recordButton);
    recordButton.addListener (this);
    
    saveButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    saveButton.setColour (TextButton::buttonColourId, Colours::red);
    saveButton.setColour (TextButton::buttonOnColourId, Colours::lightgrey);
    addAndMakeVisible (&saveButton);
    saveButton.addListener (this);
}

RecordComponent::~RecordComponent()
{
}

void RecordComponent::paint (juce::Graphics& g)
{
}

void RecordComponent::resized()
{
    auto r = getLocalBounds();
    auto row = r.removeFromTop (getHeight());
    playButton.setBounds (row.removeFromLeft (getWidth() / 3));
    recordButton.setBounds (row.removeFromLeft(getWidth() / 3));
    saveButton.setBounds ( row.removeFromLeft(getWidth() / 3));
}

void RecordComponent::buttonClicked(Button* button)
{
    if (recordPtr == nullptr)
        return;
    
    if (button == &playButton)
    {
        recordPtr->setPlayState( ! recordPtr->isPlaying());
        playButton.setToggleState ( recordPtr->isPlaying(), dontSendNotification);
        if (recordPtr->isPlaying())
            playButton.setButtonText("Stop");
        else
            playButton.setButtonText("Play");
    }
    if ( button == &recordButton)
    {
        recordPtr->setRecordState( ! recordPtr->isRecording());
        recordButton.setToggleState(recordPtr->isRecording(), dontSendNotification);
    }
}
