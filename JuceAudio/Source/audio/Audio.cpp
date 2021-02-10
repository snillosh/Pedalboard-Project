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
    for (int i = 0; i < 6; i++)
    {
        delay[i].initialise();
        tremolo[i].intitialise();
        phaser[i].initialise();
        reverberation[i].initialise();
    }
    
    
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


Pedal* Audio::getAudioPedal(int pedalToGet) const
{
    if (pedalToGet == 1) // get first pedal pointer in array
    {
        return pedal[0]; // return pedal 0
    }
    if (pedalToGet == 2)
    {
        return pedal[1]; // return pedal 1
    }
    if (pedalToGet == 3)
    {
        return pedal[2]; // return pedal 2
    }
    if (pedalToGet == 4)
    {
        return pedal[3]; // return pedal 3
    }
    if (pedalToGet == 5)
    {
        return pedal[4]; // return pedal 4
    }
    if (pedalToGet == 6)
    {
        return pedal[5]; // return pedal 5
    }
    else
    {
        return 0;
    }
}

void Audio::setAudioPedal(int pedalToSet,int index)
{
    if (pedalToSet == 1)
    {
        if (index == 1)
            pedal[0] = &phaser[0];
        if (index == 2)
            pedal[0] = &tremolo[0];
        if (index == 3)
            pedal[0] = &reverberation[0];
        if (index == 4)
            pedal[0] = &delay[0];
        else if (index == 5)
            pedal[0] = &blankPedal;
    }
    if (pedalToSet == 2)
    {
        if (index == 1)
            pedal[1] = &phaser[1];
        if (index == 2)
            pedal[1] = &tremolo[1];
        if (index == 3)
            pedal[1] = &reverberation[1];
        if (index == 4)
            pedal[1] = &delay[1];
        else if (index == 5)
            pedal[1] = &blankPedal;
    }
    if (pedalToSet == 3)
    {
        if (index == 1)
            pedal[2] = &phaser[2];
        if (index == 2)
            pedal[2] = &tremolo[2];
        if (index == 3)
            pedal[2] = &reverberation[2];
        if (index == 4)
            pedal[2] = &delay[2];
        else if (index == 5)
            pedal[2] = &blankPedal;
    }
    if (pedalToSet == 4)
    {
        if (index == 1)
            pedal[3] = &phaser[3];
        if (index == 2)
            pedal[3] = &tremolo[3];
        if (index == 3)
            pedal[3] = &reverberation[3];
        if (index == 4)
            pedal[3] = &delay[3];
        else if (index == 5)
            pedal[3] = &blankPedal;
    }
    if (pedalToSet == 5)
    {
        if (index == 1)
            pedal[4] = &phaser[4];
        if (index == 2)
            pedal[4] = &tremolo[4];
        if (index == 3)
            pedal[4] = &reverberation[4];
        if (index == 4)
            pedal[4] = &delay[4];
        else if (index == 5)
            pedal[4] = &blankPedal;
    }
    if (pedalToSet == 6)
    {
        if (index == 1)
            pedal[5] = &phaser[5];
        if (index == 2)
            pedal[5] = &tremolo[5];
        if (index == 3)
            pedal[5] = &reverberation[5];
        if (index == 4)
            pedal[5] = &delay[5];
        else if (index == 5)
            pedal[5] = &blankPedal;
    }
}

Pedal* Audio::getDelay(int delayToGet)
{
    if (delayToGet == 1)
    {
        return &delay[0];
    }
    if (delayToGet == 2)
    {
        return &delay[1];
    }
    if (delayToGet == 3)
    {
        return &delay[2];
    }
    if (delayToGet == 4)
    {
        return &delay[3];
    }
    if (delayToGet == 5)
    {
        return &delay[4];
    }
    if (delayToGet == 6)
    {
        return &delay[5];
    }
    else
    {
        return 0;
    }
}

Pedal* Audio::getPhaser(int phaserToGet)
{
    if (phaserToGet == 1)
    {
        return &phaser[0];
    }
    if (phaserToGet == 2)
    {
        return &phaser[1];
    }
    if (phaserToGet == 3)
    {
        return &phaser[2];
    }
    if (phaserToGet == 4)
    {
        return &phaser[3];
    }
    if (phaserToGet == 5)
    {
        return &phaser[4];
    }
    if (phaserToGet == 6)
    {
        return &phaser[5];
    }
    else
    {
        return 0;
    }
}

Pedal* Audio::getTremolo(int tremoloToGet)
{
    if (tremoloToGet == 1)
    {
        return &tremolo[0];
    }
    if (tremoloToGet == 2)
    {
        return &tremolo[1];
    }
    if (tremoloToGet == 3)
    {
        return &tremolo[2];
    }
    if (tremoloToGet == 4)
    {
        return &tremolo[3];
    }
    if (tremoloToGet == 5)
    {
        return &tremolo[4];
    }
    if (tremoloToGet == 6)
    {
        return &tremolo[5];
    }
    else
    {
        return 0;
    }
}

Pedal* Audio::getReverberation(int reverberationToGet)
{
    if (reverberationToGet == 1)
    {
        return &reverberation[0];
    }
    if (reverberationToGet == 2)
    {
        return &reverberation[1];
    }
    if (reverberationToGet == 3)
    {
        return &reverberation[2];
    }
    if (reverberationToGet == 4)
    {
        return &reverberation[3];
    }
    if (reverberationToGet == 5)
    {
        return &reverberation[4];
    }
    if (reverberationToGet == 6)
    {
        return &reverberation[5];
    }
    else
    {
        return 0;
    }
}

Pedal* Audio::getBlankPedal()
{
    return &blankPedal;
}
