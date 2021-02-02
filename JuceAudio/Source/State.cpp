/*
  ==============================================================================

    State.cpp
    Created: 22 Jan 2021 11:28:38pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "State.h"

const Identifier State::PARAMETERS = "PARAMETERS";
const Identifier State::SliderValue = "SliderValue";
const Identifier State::ButtonValue = "ButtonValue";

State::State()
{
    valueTree = ValueTree (PARAMETERS);
    DBG(valueTree.toXmlString());
}
State::~State()
{
    
}
