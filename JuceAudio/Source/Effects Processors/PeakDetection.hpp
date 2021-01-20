/*
  ==============================================================================

    PeakDetection.hpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

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
