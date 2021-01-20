/*
  ==============================================================================

    Phaser.cpp
    Created: 12 Jan 2021 11:17:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "Phaser.hpp"


Phaser::Phaser()
{
    
}

Phaser::~Phaser()
{
    
}

void Phaser::setParameter1(float input)
{
}
float Phaser::getParameter1() const
{
}
//----------------------------------------
void Phaser::setParameter2(float input)
{
}
float Phaser::getParameter2() const
{
}
//----------------------------------------
void Phaser::setParameter3(float input)
{
}
float Phaser::getParameter3() const
{
}
//----------------------------------------
void Phaser::setParameter4(float input)
{
}
float Phaser::getParameter4() const
{
}
//----------------------------------------
void Phaser::setParameter5(float input)
{
}
float Phaser::getParameter5() const
{
}
//----------------------------------------
float Phaser::process(float input)
{
    if (isOn())
    {
        return input;
    }
    else
        return input;
}


