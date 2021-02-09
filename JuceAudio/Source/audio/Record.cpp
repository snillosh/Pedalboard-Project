/*
  ==============================================================================

    Record.cpp
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Record.h"



Record::Record()
{
    audioBuffer.setSize(1, 176400);
    audioBuffer.clear();
}

Record::~Record()
{
    
}

void Record::setPlayState(const bool newState)
{
    playState = newState;
}

bool Record::isPlaying() const
{
    return playState.load();
}

void Record::setRecordState(const bool newState)
{
    recordState = newState;
}

bool Record::isRecording() const
{
    return recordState.load();
}

void Record::reset()
{
    DBG("Cleared");
    audioBuffer.clear();
}

float Record::processSample(float input)
{
    auto output = input;
    if (playState.load() == true)
    {
        float* audioSample;
        audioSample = audioBuffer.getWritePointer(0, bufferPosition);
        //play
        output = *audioSample;
        //click 4 times each bufferLength
        if ((bufferPosition % (176400 / 8)) == 0)
            *audioSample += 0.25f;
        
        //record
        if (recordState.load() == true)
            *audioSample = input + output;
        
        //increment and cycle the buffer counter
        if (++bufferPosition == 176400)
            bufferPosition = 0;
    }
    return output;
}
