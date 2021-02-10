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
    /** Audio Constructor */
    Audio();
    
    /** Audio Destructor */
    ~Audio();
    
    
    /** Returns a pointer to the pedal object based on the pedal entered.
     @param pedalToGet the index of the pedal pointer that's being returned (1-6)
     @return pointer to the pedal */
    Pedal* getAudioPedal(int pedalToGet) const;
    
    /** Sets the entered pedal to the reference of an effect based on the index (pedal type).
     Used to set pedalGUI pedal pointer to the same as audio pointer
     @param pedalToSet the pedal that's being set (1-6)
     @param effectIndex the effect number that's being set (1-4) */
    void setAudioPedal(int pedalToSet ,int effectIndex);
    
    
    /** Returns a pointer to looper object
     @return returns looper reference*/
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
    
    /** Returns the reference of the delay object in the delay array
     @param delayToGet the delay index to return
     @return delay reference from array*/
    Pedal* getDelay(int delayToGet);
    
    /** Returns the reference of the phaser object in the phaser array
     @param phaserToGet the phaser index to return
     @return phaser reference from array*/
    Pedal* getPhaser(int phaserToGet);
    
    /** Returns the reference of the tremolo object in the tremolo array
     @param tremoloToGet the tremolo index to return
     @return tremolo reference from array*/
    Pedal* getTremolo(int tremoloToGet);
    
    /** Returns the reference of the reverberation object in the reverberation array
     @param reverberationToGet the reverberation index to return
     @return reverberation reference from array*/
    Pedal* getReverberation(int reverberationToGet);
    
    /** Return the blank pedal object reference
     @return blankPedal reference*/
    Pedal* getBlankPedal();
    
private:
    AudioDeviceManager audioDeviceManager;
    Looper looper;
    
    /** arrays of objects of each effect type corresponding to the 6 pedal slots
     Each pedal placed in a separate slot is a completly different object meaning they can work with each other*/
    std::array<Delay, 6> delay;
    std::array<Phaser, 6> phaser;
    std::array<Tremolo, 6> tremolo;
    std::array<Reverberation, 6> reverberation;
    BlankPedal blankPedal;
    
    /** an array of 6 pedal pointers is created based on the 6 process slots, with each one being used to process a casscade of audio signals*/
    std::array <Pedal* , 6> pedal;
    
    float sampleRate = 44100.0f;
};
