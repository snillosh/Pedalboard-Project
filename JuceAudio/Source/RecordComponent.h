/*
  ==============================================================================

    RecordComponent.h
    Created: 18 Jan 2021 5:22:14pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Record.h"

//==============================================================================
/*
*/
class RecordComponent  : public Component,
                         public Button::Listener
{
public:
    RecordComponent();
    ~RecordComponent() override;
    
    void setRecord (Record* recordPtr);
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked (Button*) override;

private:
    Record* recordPtr             {nullptr};
    TextButton recordButton       {"Record"};
    TextButton saveButton         {"Save"};
    TextButton playButton         {"Play"};
};
