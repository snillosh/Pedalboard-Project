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
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/Effects Processors/BlankPedal.h"
#include "Looper.h"
/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
                public AudioIODeviceCallback
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
    
    //Returns a pointer to the pedal object based on the pedal entered.
    Pedal* getPedal(int pedalToGet) const;
    //Sets the entered pedal to the reference of an effect based on the index (pedal type)
    void setPedal(int pedalToSet ,int index);
    //Returns a pointer to record object
    Looper* getLooper() {return &looper;}

    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager;}
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    
    void audioDeviceIOCallback (const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples) override;
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;
    
    //Returns a reference of the delay object
    Pedal* getDelay();
    //Returns a reference of the phaser object
    Pedal* getPhaser();
    //Returns a reference of the tremolo oject
    Pedal* getTremolo();
    //Returns a reference of the reverberation object
    Pedal* getReverberation();
    //Returns a reference of the blank pedal object
    Pedal* getBlankPedal();
    
private:
    AudioDeviceManager audioDeviceManager;
    Looper looper;
    
    Delay delay;
    Phaser phaser;
    Tremolo tremolo;
    Reverberation reverberation;
    BlankPedal blankPedal;
    
    // an array of 6 pedal pointers is created based on the 6 process slots, with each one being used to process a casscade of audio signals
    std::array <Pedal* , 6> pedal;
    
    float sampleRate = 44100.0f;
};
