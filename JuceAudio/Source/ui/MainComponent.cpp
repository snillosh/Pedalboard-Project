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
    
    for (int index = 0; index < 6; ++index)
      comboBoxVector.emplace_back(std::make_unique<ComboBox>());
    
    for (auto& b : comboBoxVector)
    {
        addAndMakeVisible(b.get());
        b.get()->addItem ("Phaser", 1);
        b.get()->addItem ("Compressor", 2);
        b.get()->addItem ("Reverb", 3);
        b.get()->addItem ("Delay", 4);
        b.get()->addItem ("None", 5);
        b.get()->setSelectedId(5);
        b.get()->addListener(this);
    }
    
    pedalAmountSelector.addItem("1", 1);
    pedalAmountSelector.addItem("2", 2);
    pedalAmountSelector.addItem("3", 3);
    pedalAmountSelector.addItem("4", 4);
    pedalAmountSelector.addItem("5", 5);
    pedalAmountSelector.addItem("6", 6);
    pedalAmountSelector.setSelectedId(4);
    pedalAmountSelector.addListener(this);
    addAndMakeVisible(pedalAmountSelector);
    
    for (int index = 0; index < 6; ++index)
      pedalGUIVector.emplace_back(std::make_unique<PedalGUI>());
    
    for(auto& p : pedalGUIVector)
        addAndMakeVisible (p.get());
    
    for (int i = 0; i < pedalGUIVector.size(); i++)
    {
        pedalGUIVector[i]->setPedal (audio.getPedal(i + 1));
    }
    
    addAndMakeVisible(recordComponent);
    resized();
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::resized()
{
    auto r = getLocalBounds();
    
    auto row = r.removeFromTop (getHeight() / 16);
    
    auto row2 = r.removeFromBottom(getHeight() * 0.90);
    
    auto row3 = r.removeFromTop(getHeight()/ 32);
    
    auto recordComp = row.removeFromTop(getHeight()/16);
    
    for (auto& b : comboBoxVector)
        b.get()->setBounds(row3.removeFromLeft(getWidth() / pedalAmount));
    
    recordComponent.setBounds (recordComp.removeFromRight (getWidth() * 0.75));
    
    pedalAmountSelector.setBounds(recordComp.removeFromLeft(getWidth()/4));
    
    for (auto& p : pedalGUIVector)
        p.get()->setBounds (row2.removeFromLeft (getWidth() /pedalAmount));
}
void MainComponent::paint (Graphics& g)
{
    auto r = getLocalBounds();
    
    g.setColour(Colours::lightblue);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::lightcyan);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::lightblue);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::lightcyan);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::lightblue);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    g.setColour(Colours::lightcyan);
    g.fillRect(r.removeFromLeft(getWidth() / pedalAmount));
    
    g.setColour(Colours::black);
    g.fillRect(0, getHeight() * 0.5, getWidth(), getHeight() / 16);
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
        pedalGUIVector[0]->resetButton();
        pedalGUIVector[0]->updateParametes(audio.getDelayPtr(), audio.getPhaserPtr(), audio.getCompressorPtr(), audio.getReverberationPtr(), audio.getNonePtr());
    }
    if (comboBoxThatHasChanged == &*comboBoxVector[1])
    {
        audio.setPedalPtr(2,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[1]->setPedal (audio.getPedal(2));
        pedalGUIVector[0]->resetButton();
        pedalGUIVector[1]->updateParametes(audio.getDelayPtr(), audio.getPhaserPtr(), audio.getCompressorPtr(), audio.getReverberationPtr(), audio.getNonePtr());
    }
        
    if (comboBoxThatHasChanged == &*comboBoxVector[2])
    {
        audio.setPedalPtr(3,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[2]->setPedal (audio.getPedal(3));
        pedalGUIVector[0]->resetButton();
        pedalGUIVector[2]->updateParametes(audio.getDelayPtr(), audio.getPhaserPtr(), audio.getCompressorPtr(), audio.getReverberationPtr(), audio.getNonePtr());
    }
        
    if (comboBoxThatHasChanged == &*comboBoxVector[3])
    {
        audio.setPedalPtr(4,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[3]->setPedal (audio.getPedal(4));
        pedalGUIVector[0]->resetButton();
        pedalGUIVector[3]->updateParametes(audio.getDelayPtr(), audio.getPhaserPtr(), audio.getCompressorPtr(), audio.getReverberationPtr(), audio.getNonePtr());
    }
    
    if (comboBoxThatHasChanged == &*comboBoxVector[4])
    {
        audio.setPedalPtr(5,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[4]->setPedal (audio.getPedal(5));
        pedalGUIVector[0]->resetButton();
        pedalGUIVector[4]->updateParametes(audio.getDelayPtr(), audio.getPhaserPtr(), audio.getCompressorPtr(), audio.getReverberationPtr(), audio.getNonePtr());
    }
    
    if (comboBoxThatHasChanged == &*comboBoxVector[5])
    {
        audio.setPedalPtr(6,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[5]->setPedal (audio.getPedal(6));
        pedalGUIVector[0]->resetButton();
        pedalGUIVector[5]->updateParametes(audio.getDelayPtr(), audio.getPhaserPtr(), audio.getCompressorPtr(), audio.getReverberationPtr(), audio.getNonePtr());
    }
    
    
    if(comboBoxThatHasChanged == &pedalAmountSelector)
    {
        pedalAmount = comboBoxThatHasChanged->getSelectedId();
        repaint();
        resized();
    }
}
