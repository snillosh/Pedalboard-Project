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

float Compressor::process(float input)
{
    if (isOn())
    {
        return input;
    }
    else
        return input;
}

void Compressor::setParameter1(float input)
{
    
}
void Compressor::setParameter2(float input)
{
    
}
void Compressor::setParameter3(float input)
{
    
}
void Compressor::setParameter4(float input)
{
    
}
void Compressor::setParameter5(float input)
{
    
}
