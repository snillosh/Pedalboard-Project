/*
  ==============================================================================

    Audio.h
    Created: 09 Jan 2021 4:16:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <array>
#include "Pedal.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Delay.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Compressor.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Phaser.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Reverberation.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/None.h"
/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
                public AudioIODeviceCallback
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
    Pedal* getPedal(int pedalToGet);
    void setPedalPtr(int pedalToSet ,int index);

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
    
    Delay delay;
    Phaser phaser;
    Compressor compressor;
    Reverberation reverberation;
    None none;
    
    Pedal* pedalPtr1;
    Pedal* pedalPtr2;
    Pedal* pedalPtr3;
    Pedal* pedalPtr4;
    Pedal* pedalPtr5;
    Pedal* pedalPtr6;
    
    double sampleRate;
};
