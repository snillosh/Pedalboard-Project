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
    pedal[0] = &blankPedal;
    pedal[1] = &blankPedal;
    pedal[2] = &blankPedal;
    pedal[3] = &blankPedal;
    pedal[4] = &blankPedal;
    pedal[5] = &blankPedal;
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
        //each process slot represents the 6 possible pedals running at a time
        //the input signal is run through each pedal where (depending on the pedal selected) the process function of the effect gets applied to the signal
        auto pedalProcessSlot1 = pedal[0]->process(input);
        auto pedalProcessSlot2 = pedal[1]->process(pedalProcessSlot1);
        auto pedalProcessSlot3 = pedal[2]->process(pedalProcessSlot2);
        auto pedalProcessSlot4 = pedal[3]->process(pedalProcessSlot3);
        auto pedalProcessSlot5 = pedal[4]->process(pedalProcessSlot4);
        auto pedalProcessSlot6 = pedal[5]->process(pedalProcessSlot5);
        //after outputing from the pedals, the signal is run through the looper 
        auto output = looper.processSample(pedalProcessSlot6);
        
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
        return pedal[0];
    }
    if (pedalToGet == 2)
    {
        return pedal[1];
    }
    if (pedalToGet == 3)
    {
        return pedal[2];
    }
    if (pedalToGet == 4)
    {
        return pedal[3];
    }
    if (pedalToGet == 5)
    {
        return pedal[4];
    }
    if (pedalToGet == 6)
    {
        return pedal[5];
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
            pedal[0] = &phaser;
        if (index == 2)
            pedal[0] = &tremolo;
        if (index == 3)
            pedal[0] = &reverberation;
        if (index == 4)
            pedal[0] = &delay;
        else if (index == 5)
            pedal[0] = &blankPedal;
    }
    if (pedalToSet == 2)
    {
        if (index == 1)
            pedal[1] = &phaser;
        if (index == 2)
            pedal[1] = &tremolo;
        if (index == 3)
            pedal[1] = &reverberation;
        if (index == 4)
            pedal[1] = &delay;
        else if (index == 5)
            pedal[1] = &blankPedal;
    }
    if (pedalToSet == 3)
    {
        if (index == 1)
            pedal[2] = &phaser;
        if (index == 2)
            pedal[2] = &tremolo;
        if (index == 3)
            pedal[2] = &reverberation;
        if (index == 4)
            pedal[2] = &delay;
        else if (index == 5)
            pedal[2] = &blankPedal;
    }
    if (pedalToSet == 4)
    {
        if (index == 1)
            pedal[3] = &phaser;
        if (index == 2)
            pedal[3] = &tremolo;
        if (index == 3)
            pedal[3] = &reverberation;
        if (index == 4)
            pedal[3] = &delay;
        else if (index == 5)
            pedal[3] = &blankPedal;
    }
    if (pedalToSet == 5)
    {
        if (index == 1)
            pedal[4] = &phaser;
        if (index == 2)
            pedal[4] = &tremolo;
        if (index == 3)
            pedal[4] = &reverberation;
        if (index == 4)
            pedal[4] = &delay;
        else if (index == 5)
            pedal[4] = &blankPedal;
    }
    if (pedalToSet == 6)
    {
        if (index == 1)
            pedal[5] = &phaser;
        if (index == 2)
            pedal[5] = &tremolo;
        if (index == 3)
            pedal[5] = &reverberation;
        if (index == 4)
            pedal[5] = &delay;
        else if (index == 5)
            pedal[5] = &blankPedal;
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
