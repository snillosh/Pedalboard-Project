//
//  Compressor.cpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "Compressor.hpp"


Compressor::Compressor()
{
    
}

Compressor::~Compressor()
{
    
}

void Compressor::setParameter1(float input)
{
    fThresh = input / 10.f;
}
void Compressor::setParameter2(float input)
{
    fRatio = ((input / 10.f) * 31.f) + 1.f;
}
void Compressor::setParameter3(float input)
{
    makeUp = input + 1.f;
}
void Compressor::setParameter4(float input)
{
    
}
void Compressor::setParameter5(float input)
{
    
}

void Compressor::intitialise()
{
    peak.initalise(0.001 * 44100);
}

float Compressor::Compress(float x){
    float y = 0.0;
    if(x > fThresh){ // When the input siganl is above the threshold
        y = fThresh + (x-fThresh)/fRatio; // divide any signal above the threshold by the ratio
    }
    else {
        y = x; // Else the input siganl = output signal
    }
    return y / x; // Return gain reduction for the gain stage
}

float Compressor::process(float input)
{
    if (isOn())
    {
        peakValue = peak.process(input);
        gainReduction = Compress(peakValue);
        return input * gainReduction * makeUp;
    }
    else
    {
        return input;
    }
        
}


