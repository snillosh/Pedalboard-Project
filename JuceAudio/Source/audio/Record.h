/*
  ==============================================================================

    Record.h
    Created: 18 Jan 2021 5:23:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Record
{
public:
    Record();
    ~Record();
    
    void setPlayState (bool newState);
    
    bool isPlaying() const;
    
    void setRecordState (bool newState);
    
    bool isRecording() const;
    
    float processSample (float input);
    
private:
    std::atomic<int> recordState {false};
    std::atomic<int> playState {false};
    
    unsigned int bufferPosition {0};
    std::array<float, 88200> audioBuffer;
};
