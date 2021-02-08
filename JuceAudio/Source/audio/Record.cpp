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
    audioBuffer.fill (0.f);
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

float Record::processSample(float input)
{
    auto output = 0.f;
    if (playState.load() == true)
    {
        output = audioBuffer[bufferPosition];
        
        if((bufferPosition % (audioBuffer.size() / 4)) == 0)
            output += 0.25;
        
        if (recordState.load() == true)
            audioBuffer[bufferPosition] = input;
        
        if (++bufferPosition == audioBuffer.size())
            bufferPosition = 0;
    }
    return output;
}
