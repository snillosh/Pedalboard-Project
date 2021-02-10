/*
  ==============================================================================

    Looper.cpp
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Looper.h"



Looper::Looper()
{
    audioBuffer.setSize(1, 352800);
    audioBuffer.clear();
}

Looper::~Looper()
{
    
}

void Looper::setPlayState(const bool newState)
{
    playState = newState;
}

bool Looper::isPlaying() const
{
    return playState.load();
}

void Looper::setRecordState(const bool newState)
{
    recordState = newState;
}

bool Looper::isRecording() const
{
    return recordState.load();
}

void Looper::reset()
{
    DBG("Cleared");
    audioBuffer.clear();
}

void Looper::setBufferSize(int tempo)
{
    bufferPosition = 0;
    tempoValue = tempo;
    float bufferLengthInSecond = (16.0f/ tempoValue) * 60.0f;
    bufferLengthInSamples = bufferLengthInSecond * sampleRate;
    audioBuffer.setSize(1, bufferLengthInSamples);
}

float Looper::processSample(float input)
{
    auto output = input;
    if (playState.load() == true)
    {
        float* audioSample;
        audioSample = audioBuffer.getWritePointer(0, bufferPosition);
        //play
        output = *audioSample;
        //click 16 times each bufferLength
        if ((bufferPosition % (bufferLengthInSamples / 16)) == 0)
            *audioSample += 0.15f;
        if ((bufferPosition % (bufferLengthInSamples / 4)) == 0)
            *audioSample += 0.5f;
        //record
        if (recordState.load() == true)
            *audioSample = input + output;
        
        //increment and cycle the buffer counter
        if (++bufferPosition == bufferLengthInSamples)
            bufferPosition = 0;
    }
    return output;
}
