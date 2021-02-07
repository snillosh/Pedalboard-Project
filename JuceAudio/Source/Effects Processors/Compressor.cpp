/*
  ==============================================================================

    Compressor.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Compressor.hpp"


Compressor::Compressor()
{
    
}

Compressor::~Compressor()
{
    
}
//------------------------------------------------
void Compressor::setParameter1(float input)
{
    fThresh = input / 10.f;
}
float Compressor::getParameter1() const
{
    return fThresh;
}
//---------------------------------------------
void Compressor::setParameter2(float input)
{
    fRatio = ((input / 10.f) * 31.f) + 1.f;
}
float Compressor::getParameter2() const
{
    return fRatio;
}
//---------------------------------------------
void Compressor::setParameter3(float input)
{
    makeUp = input + 1.f;
}
float Compressor::getParameter3() const
{
    return makeUp;
}
//---------------------------------------------
void Compressor::setParameter4(float input)
{
}
float Compressor::getParameter4() const
{
}
//---------------------------------------------
void Compressor::setParameter5(float input)
{
}
float Compressor::getParameter5() const
{
}
//---------------------------------------------
void Compressor::intitialise()
{
    dsp::ProcessSpec spec;
    peak.initalise(0.001 * 44100);
    compress.setThreshold(20);
    compress.setRatio(16);
    compress.setAttack(16);
    compress.setRelease(100);
    compress.prepare(spec);
    
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
        DBG("COMPRESSION IN ACTION");
        return compress.processSample(0, input);
    }
    else
    {
        return input;
    }
        
}


