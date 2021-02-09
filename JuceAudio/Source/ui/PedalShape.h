/*
  ==============================================================================

    PedalShape.h
    Created: 9 Feb 2021 12:46:15am
    Author:  Bevan Salter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PedalShape  : public juce::Component
{
public:
    PedalShape();
    ~PedalShape() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalShape)
};
