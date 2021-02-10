/*
  ==============================================================================

    RecordComponent.cpp
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Looper.h"

//==============================================================================
/*
*/
class LooperGUI  : public Component,
                         public Button::Listener
{
public:
    LooperGUI();
    ~LooperGUI() override;
    
    void setLooper (Looper* newLooper);
    void setTempoValue (int newTempoValue);
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked (Button* button) override;

private:
    Looper* looper             {nullptr};
    TextButton recordButton       {"Record"};
    TextButton saveButton         {"Save"};
    TextButton playButton         {"Play"};
    TextButton resetButton        {"Reset"};
    
    int tempoValue;
};
