/*
  ==============================================================================

    Audio.cpp
    Created: 09 Jan 2021 4:16:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Audio.h"

Audio::Audio()
{
    auto midiInputDevices = MidiInput::getAvailableDevices();
    if (midiInputDevices.size() > 0)
        audioDeviceManager.setMidiInputDeviceEnabled (midiInputDevices[0].identifier, true);
    audioDeviceManager.addMidiInputCallback ("", this);
    
    auto errorMessage = audioDeviceManager.initialiseWithDefaultDevices (1, 2);
    if ( ! errorMessage.isEmpty())
        DBG (errorMessage);
    audioDeviceManager.addAudioCallback (this);
    
    dsp::ProcessSpec spec;
    sampleRate = spec.sampleRate;
    
    delay.initialise();
    compressor.intitialise();
    phaser.initialise();
    reverberation.initialise();
    
    
    pedalPtr[0] = &none;
    pedalPtr[1] = &none;
    pedalPtr[2] = &none;
    pedalPtr[3] = &none;
    pedalPtr[4] = &none;
    pedalPtr[5] = &none;
}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback (this);
    audioDeviceManager.removeMidiInputCallback ("", this);
}

void Audio::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
}

void Audio::audioDeviceIOCallback (const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples)
{
    ScopedNoDenormals noDenormals;
    
    AudioBuffer<float> buffer(outputChannelData, numOutputChannels, numSamples);

    const float* inL = inputChannelData[0];

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    
    while(numSamples--)
    {
        auto input = *inL;
        auto pedalProcessSlot1 = pedalPtr[0]->process(input);
        auto pedalProcessSlot2 = pedalPtr[1]->process(pedalProcessSlot1);
        auto pedalProcessSlot3 = pedalPtr[2]->process(pedalProcessSlot2);
        auto pedalProcessSlot4 = pedalPtr[3]->process(pedalProcessSlot3);
        auto pedalProcessSlot5 = pedalPtr[4]->process(pedalProcessSlot4);
        auto pedalProcessSlot6 = pedalPtr[5]->process(pedalProcessSlot5);
        auto output = pedalProcessSlot6;
        
        *outL = output;
        *outR = output;
        
        inL++;
        outL++;
        outR++;
    }
}


void Audio::audioDeviceAboutToStart (AudioIODevice* device)
{
}

void Audio::audioDeviceStopped()
{
}

Pedal* Audio::getPedal(int pedalToGet)
{
    if (pedalToGet == 1)
    {
        return pedalPtr[0];
    }
    if (pedalToGet == 2)
    {
        return pedalPtr[1];
    }
    if (pedalToGet == 3)
    {
        return pedalPtr[2];
    }
    if (pedalToGet == 4)
    {
        return pedalPtr[3];
    }
    if (pedalToGet == 5)
    {
        return pedalPtr[4];
    }
    if (pedalToGet == 6)
    {
        return pedalPtr[5];
    }
}

void Audio::setPedalPtr(int pedalToSet,int index)
{
    if (pedalToSet == 1)
    {
        if (index == 1)
            pedalPtr[0] = &phaser;
        if (index == 2)
            pedalPtr[0] = &compressor;
        if (index == 3)
            pedalPtr[0] = &reverberation;
        if (index == 4)
            pedalPtr[0] = &delay;
        else if (index == 5)
            pedalPtr[0] = &none;
    }
    if (pedalToSet == 2)
    {
        if (index == 1)
            pedalPtr[1] = &phaser;
        if (index == 2)
            pedalPtr[1] = &compressor;
        if (index == 3)
            pedalPtr[1] = &reverberation;
        if (index == 4)
            pedalPtr[1] = &delay;
        else if (index == 5)
            pedalPtr[1] = &none;
    }
    if (pedalToSet == 3)
    {
        if (index == 1)
            pedalPtr[2] = &phaser;
        if (index == 2)
            pedalPtr[2] = &compressor;
        if (index == 3)
            pedalPtr[2] = &reverberation;
        if (index == 4)
            pedalPtr[2] = &delay;
        else if (index == 5)
            pedalPtr[2] = &none;
    }
    if (pedalToSet == 4)
    {
        if (index == 1)
            pedalPtr[3] = &phaser;
        if (index == 2)
            pedalPtr[3] = &compressor;
        if (index == 3)
            pedalPtr[3] = &reverberation;
        if (index == 4)
            pedalPtr[3] = &delay;
        else if (index == 5)
            pedalPtr[3] = &none;
    }
    if (pedalToSet == 5)
    {
        if (index == 1)
            pedalPtr[4] = &phaser;
        if (index == 2)
            pedalPtr[4] = &compressor;
        if (index == 3)
            pedalPtr[4] = &reverberation;
        if (index == 4)
            pedalPtr[4] = &delay;
        else if (index == 5)
            pedalPtr[4] = &none;
    }
    if (pedalToSet == 6)
    {
        if (index == 1)
            pedalPtr[5] = &phaser;
        if (index == 2)
            pedalPtr[5] = &compressor;
        if (index == 3)
            pedalPtr[5] = &reverberation;
        if (index == 4)
            pedalPtr[5] = &delay;
        else if (index == 5)
            pedalPtr[5] = &none;
    }
}
