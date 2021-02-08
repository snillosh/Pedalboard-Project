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
    
    pedalPtr1 = &none;
    pedalPtr2 = &none;
    pedalPtr3 = &none;
    pedalPtr4 = &none;
    pedalPtr5 = &none;
    pedalPtr6 = &none;
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

    const float* inL = inputChannelData[0];

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    while(numSamples--)
    {
        auto input = *inL;
        auto pedalProcessSlot1 = pedalPtr1->process(input);
        auto pedalProcessSlot2 = pedalPtr2->process(pedalProcessSlot1);
        auto pedalProcessSlot3 = pedalPtr3->process(pedalProcessSlot2);
        auto pedalProcessSlot4 = pedalPtr4->process(pedalProcessSlot3);
        auto pedalProcessSlot5 = pedalPtr5->process(pedalProcessSlot4);
        auto pedalProcessSlot6 = pedalPtr6->process(pedalProcessSlot5);
        auto output = pedalProcessSlot6;
        
        if (output > 1)
        {
            output = 1;
        }
        else if (output < -1)
        {
            output = -1;
        }
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
        return pedalPtr1;
    }
    if (pedalToGet == 2)
    {
        return pedalPtr2;
    }
    if (pedalToGet == 3)
    {
        return pedalPtr3;
    }
    if (pedalToGet == 4)
    {
        return pedalPtr4;
    }
    if (pedalToGet == 5)
    {
        return pedalPtr5;
    }
    if (pedalToGet == 6)
    {
        return pedalPtr6;
    }
}

void Audio::setPedalPtr(int pedalToSet,int index)
{
    if (pedalToSet == 1)
    {
        if (index == 1)
            pedalPtr1 = &phaser;
        if (index == 2)
            pedalPtr1 = &compressor;
        if (index == 3)
            pedalPtr1 = &reverberation;
        if (index == 4)
            pedalPtr1 = &delay;
        else if (index == 5)
            pedalPtr1 = &none;
    }
    if (pedalToSet == 2)
    {
        if (index == 1)
            pedalPtr2 = &phaser;
        if (index == 2)
            pedalPtr2 = &compressor;
        if (index == 3)
            pedalPtr2 = &reverberation;
        if (index == 4)
            pedalPtr2 = &delay;
        else if (index == 5)
            pedalPtr2 = &none;
    }
    if (pedalToSet == 3)
    {
        if (index == 1)
            pedalPtr3 = &phaser;
        if (index == 2)
            pedalPtr3 = &compressor;
        if (index == 3)
            pedalPtr3 = &reverberation;
        if (index == 4)
            pedalPtr3 = &delay;
        else if (index == 5)
            pedalPtr3 = &none;
    }
    if (pedalToSet == 4)
    {
        if (index == 1)
            pedalPtr4 = &phaser;
        if (index == 2)
            pedalPtr4 = &compressor;
        if (index == 3)
            pedalPtr4 = &reverberation;
        if (index == 4)
            pedalPtr4 = &delay;
        else if (index == 5)
            pedalPtr4 = &none;
    }
    if (pedalToSet == 5)
    {
        if (index == 1)
            pedalPtr5 = &phaser;
        if (index == 2)
            pedalPtr5 = &compressor;
        if (index == 3)
            pedalPtr5 = &reverberation;
        if (index == 4)
            pedalPtr5 = &delay;
        else if (index == 5)
            pedalPtr5 = &none;
    }
    if (pedalToSet == 6)
    {
        if (index == 1)
            pedalPtr6 = &phaser;
        if (index == 2)
            pedalPtr6 = &compressor;
        if (index == 3)
            pedalPtr6 = &reverberation;
        if (index == 4)
            pedalPtr6 = &delay;
        else if (index == 5)
            pedalPtr6 = &none;
    }
}
