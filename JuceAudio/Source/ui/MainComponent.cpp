/*
  ==============================================================================

    MainComponent.cpp
    Created: 09 Jan 2021 4:15:00pm
    Author:  Bevan Salter

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent (Audio& a) :   audio (a)
{
    setSize (1280, 720);
    
    for (int i = 0; i < pedalAmount; i++)
    {
        pedalGUIVector.push_back(pedalGUI);
        comboBoxVector.push_back(pedalTypeSelector);
    }
    for (int i = 0; i < comboBoxVector.size(); i++)
    {
        addAndMakeVisible(comboBoxVector[i]);
        comboBoxVector[i].addItem ("Phaser", 1);
        comboBoxVector[i].addItem ("Compressor", 2);
        comboBoxVector[i].addItem ("Reverb", 3);
        comboBoxVector[i].addItem ("Delay", 4);
        comboBoxVector[i].addListener(this);
        pedalGUIVector[i].setPedal(audio.getPedal(i));
        addAndMakeVisible(pedalGUIVector[i]);
    }
    /*
    for (auto& b : comboBoxVector)
        addAndMakeVisible(b);
    */
    
    pedalAmountSelector.addItem("1", 1);
    pedalAmountSelector.addItem("2", 2);
    pedalAmountSelector.addItem("3", 3);
    pedalAmountSelector.addItem("4", 4);
    pedalAmountSelector.addItem("5", 5);
    pedalAmountSelector.addItem("6", 6);
    pedalAmountSelector.addListener(this);
    addAndMakeVisible(pedalAmountSelector);
    
    addAndMakeVisible(recordComponent);
    
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::resized()
{
    auto r = getLocalBounds();
    auto row = r.removeFromTop (getHeight() / 16);
    auto row2 = r.removeFromBottom(getHeight() * 0.75);
    auto row3 = r.removeFromTop(getHeight()/ 32);
    auto recordComp = row.removeFromTop(getHeight()/16);
    for (int i = 0; i < comboBoxVector.size(); i++)
    {
        comboBoxVector[i].setBounds(row3.removeFromLeft(getWidth() / pedalAmount));
    }
    /*
    for (auto& b : comboBoxVector)
        b.setBounds(row3.removeFromLeft(getWidth() / pedalAmount));
     */
    recordComponent.setBounds (recordComp.removeFromRight (getWidth() * 0.75));
    pedalAmountSelector.setBounds(recordComp.removeFromLeft(getWidth()/4));
    for (int i = 0; i < pedalGUIVector.size(); i++)
    {
        pedalGUIVector[i].setBounds(row2.removeFromLeft(getWidth()/ pedalAmount));
    }
}
void MainComponent::paint (Graphics& g)
{
    
    auto r = getLocalBounds();
    
    g.setColour(Colours::green);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::purple);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::blue);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::yellow);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));

}

//MenuBarCallbacks==============================================================
StringArray MainComponent::getMenuBarNames()
{
    auto names = { "File" };
    return StringArray (names);
}

PopupMenu MainComponent::getMenuForIndex (int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    if (topLevelMenuIndex == 0)
        menu.addItem(AudioPrefs, "Audio Prefrences", true, false);
    return menu;
}

void MainComponent::menuItemSelected (int menuItemID, int topLevelMenuIndex)
{
    if (topLevelMenuIndex == FileMenu)
    {
        if (menuItemID == AudioPrefs)
        {
            DialogWindow::LaunchOptions la;
            la.dialogTitle = "Audio Settings";
            OptionalScopedPointer<Component> osp (std::make_unique<AudioDeviceSelectorComponent>
                                                  (audio.getAudioDeviceManager(),
                                                   1, 2, 2, 2,
                                                   true, true, true, false));
            osp->setSize (450, 350);
            la.content = std::move (osp);
            la.componentToCentreAround = this;
            la.launchAsync();
        }
    }
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    for (int i = 0; i < comboBoxVector.size(); i++)
    {
        if (comboBoxThatHasChanged == &comboBoxVector[i])
        {
            audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
            pedalGUIVector[i].setPedal(audio.getPedal(i + 1));
        }
    }
    /*
    if (comboBoxThatHasChanged == &comboBoxVector[0])
    {
        audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[0].setPedal(audio.getPedal(1));
    }
    if (comboBoxThatHasChanged == &comboBoxVector[1])
    {
        audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[1].setPedal(audio.getPedal(2));
    }
        
    if (comboBoxThatHasChanged == &comboBoxVector[2])
    {
        audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[2].setPedal(audio.getPedal(3));
    }
        
    if (comboBoxThatHasChanged == &comboBoxVector[3])
    {
        audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[3].setPedal(audio.getPedal(4));
    }
    
    if (comboBoxThatHasChanged == &comboBoxVector[4])
    {
        audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[4].setPedal(audio.getPedal(5));
    }
    
    if (comboBoxThatHasChanged == &comboBoxVector[5])
    {
        audio.setPedalPtr(comboBoxThatHasChanged->getSelectedId(), comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[5].setPedal(audio.getPedal(6));
    }
    */
    if(comboBoxThatHasChanged == &pedalAmountSelector)
    {
        pedalAmount = comboBoxThatHasChanged->getSelectedId();
    }
}
