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
    audioBuffer.setSize(1, 352800); // sets audio buffer to initial size
    audioBuffer.clear(); // clear to make sure its empty
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
    audioBuffer.clear(); // empty the buffer
}

void Looper::save()
{
    FileChooser chooser ("Please selet a file: ", File::getSpecialLocation(File::userMusicDirectory), "*.wav");
    if (chooser.browseForFileToSave(true))
    {
        auto file = chooser.getResult().withFileExtension(".wav");
        auto ostream = file.createOutputStream();
        WavAudioFormat format;
        std::unique_ptr<AudioFormatWriter> writer;
        writer.reset(format.createWriterFor(ostream.get(), 44100, audioBuffer.getNumChannels(), 16, nullptr, 0));
        if (writer != nullptr)
        {
            writer->writeFromAudioSampleBuffer(audioBuffer, 0, audioBuffer.getNumSamples());
            ostream.release();
        }
    }
}

void Looper::updateBufferSize(int tempo)
{
    bufferPosition = 0; // sets audio buffer index to 0
    tempoValue = tempo;
    float bufferLengthInSecond = (16.0f/ tempoValue) * 60.0f; // converts tempo value to the length of 4 bars in seconds
    bufferLengthInSamples = bufferLengthInSecond * sampleRate; // converts seconds to samples
    audioBuffer.setSize(1, bufferLengthInSamples); // sets buffer size to new size based on tempo set by user
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
        //click 16 times each bufferLength to represent each beat
        if ((bufferPosition % (bufferLengthInSamples / 16)) == 0)
            *audioSample += 0.15f;
        //click 4 times each bufferLength to represent each bar
        if ((bufferPosition % (bufferLengthInSamples / 4)) == 0)
            *audioSample += 0.5f;
        //record
        if (recordState.load() == true)
            *audioSample = input + output;
        
        //increment and cycle the buffer counter
        if (++bufferPosition == bufferLengthInSamples)
            bufferPosition = 0;
        return output;
    }
    else
    {
        return output;
    }
}
