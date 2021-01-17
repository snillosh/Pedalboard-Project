//
//  Reverb.hpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"

class Reverberation : public Pedal
{
public:
    Reverberation();
    ~Reverberation();
    
    float process(float input) override;
    void setParameter1(float input) override;
    void setParameter2(float input) override;
    void setParameter3(float input) override;
    void setParameter4(float input) override;
    void setParameter5(float input) override;
    void initialise ();
    
private:
    float *pfCircularBuffer;
    float fSR;
    int iBufferSize;
    int iBufferWritePos;
    int iBufferReadPos;
    float fDelSig = 0;
    float fFeedbackGain;
    float fDelayTime;
    float fCutOff;
    float fOut;
};
