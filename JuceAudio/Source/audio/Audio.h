/*
  ==============================================================================

    Audio.h
    Author:  Tom Mitchell

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
                public AudioIODeviceCallback,
                public Reverb::Parameters
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
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
};
