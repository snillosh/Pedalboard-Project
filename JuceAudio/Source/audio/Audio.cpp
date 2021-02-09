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
    
    //initiates of sample rate for audio
    dsp::ProcessSpec spec;
    sampleRate = spec.sampleRate;
    
    //initialises each audio effect class ready for processing
    delay.initialise();
    tremolo.intitialise();
    phaser.initialise();
    reverberation.initialise();
    
    //initially each pedal process pointer is set to the blank pedal
    pedalPtr[0] = &blankPedal;
    pedalPtr[1] = &blankPedal;
    pedalPtr[2] = &blankPedal;
    pedalPtr[3] = &blankPedal;
    pedalPtr[4] = &blankPedal;
    pedalPtr[5] = &blankPedal;
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
        auto output = record.processSample(pedalProcessSlot6);
        
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

Pedal* Audio::getPedal(int pedalToGet) const
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
    else
    {
        return 0;
    }
}

void Audio::setPedal(int pedalToSet,int index)
{
    if (pedalToSet == 1)
    {
        if (index == 1)
            pedalPtr[0] = &phaser;
        if (index == 2)
            pedalPtr[0] = &tremolo;
        if (index == 3)
            pedalPtr[0] = &reverberation;
        if (index == 4)
            pedalPtr[0] = &delay;
        else if (index == 5)
            pedalPtr[0] = &blankPedal;
    }
    if (pedalToSet == 2)
    {
        if (index == 1)
            pedalPtr[1] = &phaser;
        if (index == 2)
            pedalPtr[1] = &tremolo;
        if (index == 3)
            pedalPtr[1] = &reverberation;
        if (index == 4)
            pedalPtr[1] = &delay;
        else if (index == 5)
            pedalPtr[1] = &blankPedal;
    }
    if (pedalToSet == 3)
    {
        if (index == 1)
            pedalPtr[2] = &phaser;
        if (index == 2)
            pedalPtr[2] = &tremolo;
        if (index == 3)
            pedalPtr[2] = &reverberation;
        if (index == 4)
            pedalPtr[2] = &delay;
        else if (index == 5)
            pedalPtr[2] = &blankPedal;
    }
    if (pedalToSet == 4)
    {
        if (index == 1)
            pedalPtr[3] = &phaser;
        if (index == 2)
            pedalPtr[3] = &tremolo;
        if (index == 3)
            pedalPtr[3] = &reverberation;
        if (index == 4)
            pedalPtr[3] = &delay;
        else if (index == 5)
            pedalPtr[3] = &blankPedal;
    }
    if (pedalToSet == 5)
    {
        if (index == 1)
            pedalPtr[4] = &phaser;
        if (index == 2)
            pedalPtr[4] = &tremolo;
        if (index == 3)
            pedalPtr[4] = &reverberation;
        if (index == 4)
            pedalPtr[4] = &delay;
        else if (index == 5)
            pedalPtr[4] = &blankPedal;
    }
    if (pedalToSet == 6)
    {
        if (index == 1)
            pedalPtr[5] = &phaser;
        if (index == 2)
            pedalPtr[5] = &tremolo;
        if (index == 3)
            pedalPtr[5] = &reverberation;
        if (index == 4)
            pedalPtr[5] = &delay;
        else if (index == 5)
            pedalPtr[5] = &blankPedal;
    }
}

Pedal* Audio::getDelay()
{
    return &delay;
}

Pedal* Audio::getPhaser()
{
    return &phaser;
}

Pedal* Audio::getTremolo()
{
    return &tremolo;
}

Pedal* Audio::getReverberation()
{
    return &reverberation;
}

Pedal* Audio::getBlankPedal()
{
    return &blankPedal;
}
