/*
  ==============================================================================

    Looper.h
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Looper
{
public:
    Looper();
    ~Looper();
    
    void setPlayState (bool newState);
    
    bool isPlaying() const;
    
    void setRecordState (bool newState);
    
    bool isRecording() const;
    
    void reset();
    
    float processSample (float input);
    
private:
    std::atomic<int> recordState {false};
    std::atomic<int> playState {false};
    std::atomic<int> resetState {false};
    
    unsigned int bufferPosition {0};
    AudioBuffer<float> audioBuffer;
};
