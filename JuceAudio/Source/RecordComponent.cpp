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
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    playButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    playButton.setColour (TextButton::buttonColourId, Colours::grey);
    playButton.setColour (TextButton::buttonOnColourId, Colours::lightgrey);
    addAndMakeVisible (&playButton);
    playButton.addListener (this);
    
    recordButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    recordButton.setColour (TextButton::buttonColourId, Colours::darkred);
    recordButton.setColour (TextButton::buttonOnColourId, Colours::red);
    addAndMakeVisible (&recordButton);
    recordButton.addListener (this);
    
    saveButton.setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    saveButton.setColour (TextButton::buttonColourId, Colours::grey);
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
    auto row = r.removeFromTop (getHeight() / 2);
    playButton.setBounds (row.removeFromLeft (getWidth() / 3));
    recordButton.setBounds (row.removeFromLeft(getWidth() / 3));
    saveButton.setBounds ( row.removeFromLeft(getWidth() / 3));
}

void RecordComponent::buttonClicked(Button *)
{
    
}

void RecordComponent::setRecord(Record *record)
{
    recordPtr = record;
}
