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
#include <vector>
#include <atomic>
#include "Pedal.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Delay.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Tremolo.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Phaser.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/Reverberation.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/None.h"
#include "Record.h"
/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
                public AudioIODeviceCallback
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
    Pedal* getPedal(int pedalToGet) const;
    void setPedalPtr(int pedalToSet ,int index);
    Record* getRecord() {return &record;}

    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager;}
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    
    void audioDeviceIOCallback (const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples) override;
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;
    
    Pedal* getDelayPtr();
    Pedal* getPhaserPtr();
    Pedal* getTremoloPtr();
    Pedal* getReverberationPtr();
    Pedal* getNonePtr();
    
    
    Delay delay;
    Phaser phaser;
    Tremolo tremolo;
    Reverberation reverberation;
    None none;
    
    /*
    Phaser* phaserPtr = &phaser;
    Delay* delayPtr = &delay;
    Compressor* compressorPtr = &compressor;
    Reverberation* reveberationPtr = &reverberation;
     */
    
private:
    AudioDeviceManager audioDeviceManager;
    Record record;
    
    
    
    std::array <Pedal* , 6> pedalPtr;
    
    double sampleRate;
};
