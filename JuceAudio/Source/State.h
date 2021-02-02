/*
  ==============================================================================

    State.h
    Created: 22 Jan 2021 11:28:38pm
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/ui/PedalGUI.hpp"


class State
{
public:
    State();
    ~State();
    static const Identifier PARAMETERS;
    static const Identifier SliderValue;
    static const Identifier ButtonValue;
private:
    ValueTree valueTree;
    PedalGUI pedalGUI;
};
