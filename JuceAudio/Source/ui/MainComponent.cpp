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
    
    for (int index = 0; index < pedalAmount; ++index)
      comboBoxVector.emplace_back(std::make_unique<ComboBox>());
    
    for (auto& b : comboBoxVector){
        addAndMakeVisible(b.get());
        b.get()->addItem ("Phaser", 1);
        b.get()->addItem ("Compressor", 2);
        b.get()->addItem ("Reverb", 3);
        b.get()->addItem ("Delay", 4);
        b.get()->addListener(this);
    }
    
    pedalAmountSelector.addItem("1", 1);
    pedalAmountSelector.addItem("2", 2);
    pedalAmountSelector.addItem("3", 3);
    pedalAmountSelector.addItem("4", 4);
    pedalAmountSelector.addItem("5", 5);
    pedalAmountSelector.addItem("6", 6);
    pedalAmountSelector.addListener(this);
    addAndMakeVisible(pedalAmountSelector);
    
    for (int index = 0; index < pedalAmount; ++index)
      pedalGUIVector.emplace_back(std::make_unique<PedalGUI>());
    
    for(auto& p : pedalGUIVector)
        addAndMakeVisible (p.get());
    
    for (int i = 0; i < pedalGUIVector.size(); i++)
    {
        pedalGUIVector[i]->setPedal (audio.getPedal(i + 1));
    }
    
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
    for (auto& b : comboBoxVector)
        b.get()->setBounds(row3.removeFromLeft(getWidth() / 4));
    recordComponent.setBounds (recordComp.removeFromRight (getWidth() * 0.75));
    pedalAmountSelector.setBounds(recordComp.removeFromLeft(getWidth()/4));
    for (auto& p : pedalGUIVector)
    {
        p.get()->setBounds (row2.removeFromLeft (getWidth() /pedalAmount));
    }
}
void MainComponent::paint (Graphics& g)
{
    
    auto r = getLocalBounds();
    /*
    auto row = r.removeFromTop(300);
    int halfWidth = getWidth() / 2.0;
    int halfHeight = getHeight() / 2.0;
    float threeQuarters = (getWidth() / 4) * 3;
     */
    g.setColour(Colours::green);
    g.fillRect(r.removeFromLeft(getWidth() / 4));
    g.setColour(Colours::purple);
    g.fillRect(r.removeFromLeft(getWidth() / 4));
    g.setColour(Colours::blue);
    g.fillRect(r.removeFromLeft(getWidth() / 4));
    g.setColour(Colours::yellow);
    g.fillRect(r.removeFromLeft(getWidth() / 4));

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
    if (comboBoxThatHasChanged == &*comboBoxVector[0])
    {
        audio.setPedalPtr(1, comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[0]->setPedal (audio.getPedal(1));
    }
    if (comboBoxThatHasChanged == &*comboBoxVector[1])
    {
        audio.setPedalPtr(2,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[1]->setPedal (audio.getPedal(2));
    }
        
    if (comboBoxThatHasChanged == &*comboBoxVector[2])
    {
        audio.setPedalPtr(3,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[3]->setPedal (audio.getPedal(3));
    }
        
    if (comboBoxThatHasChanged == &*comboBoxVector[3])
    {
        audio.setPedalPtr(4,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[4]->setPedal (audio.getPedal(4));
    }
    
    if(comboBoxThatHasChanged == &pedalAmountSelector)
    {
        pedalAmount = comboBoxThatHasChanged->getSelectedId();
    }
}
