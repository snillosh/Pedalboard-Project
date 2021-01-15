/*
  ==============================================================================

    Audio.cpp
    Author:  Tom Mitchell

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
    delay.initialise();
    
    
    pedalPtr1 = &phaser;
    pedalPtr2 = &compressor;
    pedalPtr3 = &reverberation;
    pedalPtr4 = &delay;
}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback (this);
    audioDeviceManager.removeMidiInputCallback ("", this);
}


void Audio::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
    //All MIDI inputs arrive here
    DBG ("Midi event...");

}

void Audio::audioDeviceIOCallback (const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples)
{
    //All audio processing is done here
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
        auto output = pedalProcessSlot4;
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

Pedal* Audio::getPedal(int index)
{
    return &pedal[index];
}

void Audio::setPedalPtr1(int index)
{
    DBG("Pedal Slot 1 Changed");
    if (index == 1)
        pedalPtr1 = &phaser;
    if (index == 2)
        pedalPtr1 = &compressor;
    if (index == 3)
        pedalPtr1 = &reverberation;
    else if (index == 4)
        pedalPtr1 = &delay;
}
void Audio::setPedalPtr2(int index)
{
    DBG("Pedal Slot 2 Changed");
    if (index == 1)
        pedalPtr2 = &phaser;
    if (index == 2)
        pedalPtr2 = &compressor;
    if (index == 3)
        pedalPtr2 = &reverberation;
    else if (index == 4)
        pedalPtr2 = &delay;
}
void Audio::setPedalPtr3(int index)
{
    DBG("Pedal Slot 3 Changed");
    if (index == 1)
        pedalPtr3 = &phaser;
    if (index == 2)
        pedalPtr3 = &compressor;
    if (index == 3)
        pedalPtr3 = &reverberation;
    else if (index == 4)
        pedalPtr3 = &delay;
}
void Audio::setPedalPtr4(int index)
{
    DBG("Pedal Slot 4 Changed");
    if (index == 1)
        pedalPtr4 = &phaser;
    if (index == 2)
        pedalPtr4 = &compressor;
    if (index == 3)
        pedalPtr4 = &reverberation;
    else if (index == 4)
        pedalPtr4 = &delay;
}
