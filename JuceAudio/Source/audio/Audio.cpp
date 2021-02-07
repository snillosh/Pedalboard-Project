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
    phaser.initialiser(sampleRate);
    reverberation.initialise();
    
    
    pedalPtr1 = &phaser;
    pedalPtr2 = &compressor;
    pedalPtr3 = &reverberation;
    pedalPtr4 = &delay;
    pedalPtr5 = &delay;
    pedalPtr6 = &delay;
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
        //This needs to be changed to use the JUCE audio mixer
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

Pedal* Audio::getPedal5()
{
    return pedalPtr5;
}

Pedal* Audio::getPedal6()
{
    return pedalPtr6;
}



void Audio::setPedalPtr1(int index)
{
    // these long if else need to be changed to be more concise
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
    if (index == 1)
        pedalPtr4 = &phaser;
    if (index == 2)
        pedalPtr4 = &compressor;
    if (index == 3)
        pedalPtr4 = &reverberation;
    else if (index == 4)
        pedalPtr4 = &delay;
}
void Audio::setPedalPtr5(int index)
{
    if (index == 1)
        pedalPtr5 = &phaser;
    if (index == 2)
        pedalPtr5 = &compressor;
    if (index == 3)
        pedalPtr5 = &reverberation;
    else if (index == 4)
        pedalPtr5 = &delay;
}
void Audio::setPedalPtr6(int index)
{
    if (index == 1)
        pedalPtr6 = &phaser;
    if (index == 2)
        pedalPtr6 = &compressor;
    if (index == 3)
        pedalPtr6 = &reverberation;
    else if (index == 4)
        pedalPtr6 = &delay;
}
