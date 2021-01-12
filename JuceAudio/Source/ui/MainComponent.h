/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <array>
#include "../audio/Audio.h"
#include "PedalGUI.hpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public MenuBarModel
{
public:
    //==============================================================================
    /** Constructor */
    MainComponent (Audio& a);

    /** Destructor */
    ~MainComponent();

    //Comoponent====================================================================
    void resized() override;
    void paint (Graphics&) override;
    
    //MenuBarEnums/MenuBarModel=====================================================
    enum Menus
    {
        FileMenu = 0,
        
        NumMenus
    };
    
    enum FileMenuItems
    {
        AudioPrefs = 1,
        
        NumFileItems
    };
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int topLevelMenuIndex, const String& menuName) override;
    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override;
    
private:
    Audio& audio;
    std::array<ComboBox,4> comboBoxs;
    std::array<PedalGUI, 1> pedal;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
