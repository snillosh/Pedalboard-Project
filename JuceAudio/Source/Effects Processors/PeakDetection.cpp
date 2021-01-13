//
//  PeakDetection.cpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 13/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "PeakDetection.hpp"



void peakDetection::initalise(int sampleLength, int sampleRate)
{
    iMeasuredLength = sampleLength; // set length of samples to measure
    iMeasuredItems = 0; // set starting variables to 0
    fMax = fMaxold = 0;
    sr = sampleRate;
}

float peakDetection::process(float input)
{
    fMaxold = fMaxNew; // Set current peak to become the previous peak
    fAval = fabs(input); // Take absolute + or - value from input sample
    iMeasuredItems = iMeasuredItems + 1;
    if (fAval > fMax){ // If new sample is larger than sample stored then...
        fMax = fAval; // New sample is stored as largest sample
        fMax = fMax * (40-1) + 1;
        fMax = log10(fMax); // Convert sample into logerithmic domain
    }
    if (iMeasuredItems >= iMeasuredLength){ // Once the block of samples has been reached..
        fMaxNew = fMax; // Set largest sample to new largest sample
        fMax = 0; // Reset variables
        iMeasuredItems = 0;
    }
    //double  att = (fAttack == 0.0) ? (0.0) : exp (-1.0 / (sr * fAttack)); // Set coefficients for attack and release
    //double  rel = (fRelease == 0.0) ? (0.0) : exp (-1.0 / (sr * fRelease));
    float coeff = (fMaxNew > fMaxold) ? 0.1 : 0.0003; // Set envelope to either attack or release
    return fMaxold = coeff * fMaxNew + (1-coeff) * fMaxold; // Apply envelope to peak and return it
}
