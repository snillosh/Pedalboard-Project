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
/** Looper GUI class for displaying and listening to looper buttons in mainComponent*/
class LooperGUI  :  public Component,
                    public Button::Listener
{
public:
    /** LooperGUI Constructor*/
    LooperGUI();
    /** LooperGUI Destructor*/
    ~LooperGUI() override;
    
    /** Sets the looper to the looper object in audio
     @param newLooper looper to set to*/
    void setLooper (Looper* newLooper);
    
    /** Sets the tempo value
     @param newTempoValue sets tempo value*/
    void setTempoValue (int newTempoValue);
    
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked (Button* button) override;

private:
    
    Looper* looper             {nullptr};  // pointer to looper
    TextButton recordButton       {"Record"};
    TextButton saveButton         {"Save"};
    TextButton playButton         {"Play"};
    TextButton resetButton        {"Reset"};
    
    int tempoValue;
};
