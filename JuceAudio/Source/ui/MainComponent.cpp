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
    setSize (1280, 720); // set initial window size
    
    looperGUI.setLooper(audio.getLooper()); // sets looper gui pointer to audio looper
    
    for (int index = 0; index < 6; ++index) // for each pedal slot
      effectSelectorComboBoxVector.emplace_back(std::make_unique<ComboBox>()); // put comboBox in vector
    
    for (auto& b : effectSelectorComboBoxVector) // for each combobox vector
    {
        addAndMakeVisible(b.get());
        b.get()->addItem ("Phaser", 1); // add text to combobox
        b.get()->addItem ("Tremolo", 2);
        b.get()->addItem ("Reverb", 3);
        b.get()->addItem ("Delay", 4);
        b.get()->addItem ("None", 5);
        b.get()->setSelectedId(5);     // set inital combobox text as "None:
        b.get()->addListener(this);
    }
    
    pedalAmountSelector.addItem("1", 1); // add text to pedal amount selector
    pedalAmountSelector.addItem("2", 2);
    pedalAmountSelector.addItem("3", 3);
    pedalAmountSelector.addItem("4", 4);
    pedalAmountSelector.addItem("5", 5);
    pedalAmountSelector.addItem("6", 6);
    pedalAmountSelector.setSelectedId(4);
    pedalAmountSelector.addListener(this);
    addAndMakeVisible(pedalAmountSelector);
    
    for (int index = 0; index < 6; ++index)
      pedalGUIVector.emplace_back(std::make_unique<PedalGUI>()); // put pedalGui object in vector
    
    for(auto& p : pedalGUIVector)
        addAndMakeVisible (p.get());
    
    for (int i = 0; i < pedalGUIVector.size(); i++)
    {
        pedalGUIVector[i]->setGUIPedal (audio.getAudioPedal(i + 1));  // set pointer for pedalGui
    }
    
    addAndMakeVisible(looperGUI);
    
    tempoTextBox.setInputRestrictions(3, "0123456789");              // only numbers can be entered
    tempoTextBox.setTextToShowWhenEmpty("120", Colours::white);      // set default text
    addAndMakeVisible(tempoTextBox);
    tempoTextBox.addListener(this);
    
    resized();   // resize to update changes
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::resized()     // set bounds for each object in mainComponent
{
    auto r = getLocalBounds();
    
    auto row = r.removeFromTop (getHeight() / 16);
    
    auto row2 = r.removeFromBottom(getHeight() * 0.90);
    
    auto row3 = r.removeFromTop(getHeight()/ 32);
    
    auto recordComp = row.removeFromTop(getHeight()/16);
    
    for (auto& b : effectSelectorComboBoxVector)
        b.get()->setBounds(row3.removeFromLeft(getWidth() / pedalAmount));
    
    looperGUI.setBounds (recordComp.removeFromRight (getWidth() * 0.75));
    
    pedalAmountSelector.setBounds(0, 0, getWidth() / 4, getHeight() / 32);
    
    tempoTextBox.setBounds(0, getHeight() / 32, getWidth() / 4, getHeight() / 32);
    
    for (auto& p : pedalGUIVector)
        p.get()->setBounds (row2.removeFromLeft (getWidth() /pedalAmount));
}
void MainComponent::paint (Graphics& g) // paint background
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
    if (comboBoxThatHasChanged == &*effectSelectorComboBoxVector[0])
    {
        audio.setAudioPedal(1, comboBoxThatHasChanged->getSelectedId()); // sets effect to process
        pedalGUIVector[0]->setGUIPedal (audio.getAudioPedal(1));         // sets pedalGUI 1 to audio pedal 1
        pedalGUIVector[0]->updateGUIParameters(audio.getDelay(1), audio.getPhaser(1), audio.getTremolo(1), audio.getReverberation(1), audio.getBlankPedal()); // input effect references to pedalGUI
    }
    if (comboBoxThatHasChanged == &*effectSelectorComboBoxVector[1])
    {
        audio.setAudioPedal(2,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[1]->setGUIPedal (audio.getAudioPedal(2));
        pedalGUIVector[1]->updateGUIParameters(audio.getDelay(2), audio.getPhaser(2), audio.getTremolo(2), audio.getReverberation(2), audio.getBlankPedal());
    }
        
    if (comboBoxThatHasChanged == &*effectSelectorComboBoxVector[2])
    {
        audio.setAudioPedal(3,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[2]->setGUIPedal (audio.getAudioPedal(3));
        pedalGUIVector[2]->updateGUIParameters(audio.getDelay(3), audio.getPhaser(3), audio.getTremolo(3), audio.getReverberation(3), audio.getBlankPedal());
    }
        
    if (comboBoxThatHasChanged == &*effectSelectorComboBoxVector[3])
    {
        audio.setAudioPedal(4,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[3]->setGUIPedal (audio.getAudioPedal(4));
        pedalGUIVector[3]->updateGUIParameters(audio.getDelay(4), audio.getPhaser(4), audio.getTremolo(4), audio.getReverberation(4), audio.getBlankPedal());
    }
    
    if (comboBoxThatHasChanged == &*effectSelectorComboBoxVector[4])
    {
        audio.setAudioPedal(5,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[4]->setGUIPedal (audio.getAudioPedal(5));
        pedalGUIVector[4]->updateGUIParameters(audio.getDelay(5), audio.getPhaser(5), audio.getTremolo(5), audio.getReverberation(5), audio.getBlankPedal());
    }
    
    if (comboBoxThatHasChanged == &*effectSelectorComboBoxVector[5])
    {
        audio.setAudioPedal(6,comboBoxThatHasChanged->getSelectedId());
        pedalGUIVector[5]->setGUIPedal (audio.getAudioPedal(6));
        pedalGUIVector[5]->updateGUIParameters(audio.getDelay(6), audio.getPhaser(6), audio.getTremolo(6), audio.getReverberation(6), audio.getBlankPedal());
    }
    
    
    if(comboBoxThatHasChanged == &pedalAmountSelector)
    {
        pedalAmount = comboBoxThatHasChanged->getSelectedId(); // set pedal amount to dropdown box
        repaint();
        resized();
    }
}

void MainComponent::textEditorReturnKeyPressed (TextEditor& text) // when return key is pressed on the tempo textEditor
{
    juce::String tempoValue = text.getText();
    int tempoValueInt = tempoValue.getIntValue();
    looperGUI.setTempoValue(tempoValueInt); // send tempo value to looper Gui
}
