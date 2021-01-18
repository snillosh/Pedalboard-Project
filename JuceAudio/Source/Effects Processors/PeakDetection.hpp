//
//  PeakDetection.hpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 13/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include <JuceHeader.h>


class peakDetection
{
public:
    void initalise(int sampleLength);
    float process(float input);
private:
    int iMeasuredLength, iMeasuredItems, sr;
    float fMax, fMaxold, fAval, fMaxNew;
};
