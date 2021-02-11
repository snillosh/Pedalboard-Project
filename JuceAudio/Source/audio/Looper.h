/*
  ==============================================================================

    Looper.h
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

/** Simple audio looper class - loops an audio buffer and records its input into the buffer.
    Also produces a click 4 times each loop.    */
class Looper
{
public:
    /** Looper Constructor  */
    Looper();
    /** Looper destructor*/
    ~Looper();
    
    /** Starts or stops playback of the looper
     @param newState sets the new state of the playback*/
    void setPlayState (bool newState);
    
    /** Returns the current playback state of the looper
     @return the current playback state*/
    bool isPlaying() const;
    
    /** Sets/unsets the record state of the looper
     @param newState sets the new state of the record*/
    void setRecordState (bool newState);
    
    /** Gets the current record state of the looper
     @return the current recording state*/
    bool isRecording() const;
    
    /** resets the looper by clearing the buffer*/
    void reset();
    
    /** saves the audio with the audio buffer*/
    void save();
    
    /** updates the audio buffer while the application is running.
     Used when user updates the tempo of the looper*/
    void updateBufferSize(int tempo);
    
    /** Returns processed audio sample by sample.
     @param input the input to the looper
     @return process sample*/
    float processSample (float input);
    
private:
    // Atomic state variables
    std::atomic<int> recordState {false};
    std::atomic<int> playState {false};
    std::atomic<int> resetState {false};
    
    //Audio buffer variables
    unsigned int bufferPosition {0};
    AudioBuffer<float> audioBuffer;
    
    int tempoValue;
    int bufferLengthInSamples = 352800;
    float sampleRate = 44100.0f;
};
