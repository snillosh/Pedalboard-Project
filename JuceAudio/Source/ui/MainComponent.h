/*
  ==============================================================================

    MainComponent.h
    Created: 09 Jan 2021 4:15:00pm
    Author:  Bevan Salter


  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <array>
#include <vector>
#include "../audio/Audio.h"
#include "PedalGUI.hpp"
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/LooperGUI.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public MenuBarModel,
                        public ComboBox::Listener
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
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    
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
    Audio& audio;  // reference to audio
    
    std::vector<std::unique_ptr<PedalGUI>> pedalGUIVector;   //vector of pedalGUI objects created on the ???????????????
    std::vector<std::unique_ptr<ComboBox>> effectSelectorComboBoxVector; // vector of
    LooperGUI looperGUI; //creates an instance of the GUI for the record feature
    ComboBox pedalAmountSelector; // creates a combobox to select the amount of pedal slots
    
    int pedalAmount = 4;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
