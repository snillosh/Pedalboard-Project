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


Pedal* Audio::getPedal1()
{
    return pedalPtr1;
}

Pedal* Audio::getPedal2()
{
    return pedalPtr2;
}

Pedal* Audio::getPedal3()
{
    return pedalPtr3;
}

Pedal* Audio::getPedal4()
{
    return pedalPtr4;
}


void Audio::setPedalPtr1(int index)
{
    
    if (index == 1){
        pedalPtr1 = &phaser;
        DBG("Pedal Slot 1 changed to a phaser");
    }
    if (index == 2)
    {
        pedalPtr1 = &compressor;
        DBG("Pedal Slot 1 changed to a compressor");
    }
    if (index == 3)
    {
        pedalPtr1 = &reverberation;
        DBG("Pedal Slot 1 changed to a reverb");
    }
    else if (index == 4)
    {
        pedalPtr1 = &delay;
        DBG("Pedal Slot 1 changed to a delay");
    }
}
void Audio::setPedalPtr2(int index)
{
    if (index == 1){
        pedalPtr2 = &phaser;
        DBG("Pedal Slot 2 changed to a phaser");
    }
    if (index == 2)
    {
        pedalPtr2 = &compressor;
        DBG("Pedal Slot 2 changed to a compressor");
    }
    if (index == 3)
    {
        pedalPtr2 = &reverberation;
        DBG("Pedal Slot 2 changed to a reverb");
    }
    else if (index == 4)
    {
        pedalPtr2 = &delay;
        DBG("Pedal Slot 2 changed to a delay");
    }
}
void Audio::setPedalPtr3(int index)
{
    if (index == 1){
        pedalPtr3 = &phaser;
        DBG("Pedal Slot 3 changed to a phaser");
    }
    if (index == 2)
    {
        pedalPtr3 = &compressor;
        DBG("Pedal Slot 3 changed to a compressor");
    }
    if (index == 3)
    {
        pedalPtr3 = &reverberation;
        DBG("Pedal Slot 3 changed to a reverb");
    }
    else if (index == 4)
    {
        pedalPtr3 = &delay;
        DBG("Pedal Slot 3 changed to a delay");
    }
}
void Audio::setPedalPtr4(int index)
{
    if (index == 1){
        pedalPtr4 = &phaser;
        DBG("Pedal Slot 4 changed to a phaser");
    }
    if (index == 2)
    {
        pedalPtr4 = &compressor;
        DBG("Pedal Slot 4 changed to a compressor");
    }
    if (index == 3)
    {
        pedalPtr4 = &reverberation;
        DBG("Pedal Slot 4 changed to a reverb");
    }
    else if (index == 4)
    {
        pedalPtr4 = &delay;
        DBG("Pedal Slot 4 changed to a delay");
    }
}
