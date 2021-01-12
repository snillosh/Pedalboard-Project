/*
  ==============================================================================

    Audio.h
    Author:  Tom Mitchell

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <array>
#include "Pedal.hpp"

/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
                public AudioIODeviceCallback
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
    Pedal* getPedal(int index)  {return &pedal1[index];}
    
    /** Returns the audio device manager, don't keep a copy of it! */
    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager;}
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    
    void audioDeviceIOCallback (const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples) override;
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;
private:
    AudioDeviceManager audioDeviceManager;
    std::array<Pedal, 1> pedal1;
};