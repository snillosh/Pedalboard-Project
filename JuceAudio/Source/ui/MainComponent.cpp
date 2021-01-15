/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent (Audio& a) :   audio (a)
{
    setSize (1920, 1080);
    for (auto& b : comboBoxs)
        addAndMakeVisible(b);
    
    for (int i = 0; i < 4; i++)
    {
        comboBoxs[i].addItem ("Phaser", 1);
        comboBoxs[i].addItem ("Compressor", 2);
        comboBoxs[i].addItem ("Reverb", 3);
        comboBoxs[i].addItem ("Delay", 4);
    }
    
    pedal[0].setPedal (audio.getPedal(0));
    addAndMakeVisible(pedal[0]);
    
    pedal[1].setPedal (audio.getPedal(1));
    addAndMakeVisible(pedal[1]);
    
    pedal[2].setPedal (audio.getPedal(2));
    addAndMakeVisible(pedal[1]);
    
    pedal[3].setPedal (audio.getPedal(3));
    addAndMakeVisible(pedal[3]);
    /*
    for (int i = 0; i<= pedal.size(); i++)
     {
        pedal[i].setPedal(audio.getPedal(i));
        addAndMakeVisible(pedal[i]);
     }
     */
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::resized()
{
    auto r = getLocalBounds();
    auto row = r.removeFromTop (40);
    for (auto& b : comboBoxs)
        b.setBounds(row.removeFromLeft(getWidth() / 4));
    pedal[0].setBounds (r.removeFromTop (100));
    pedal[1].setBounds (r.removeFromTop(100));
    pedal[2].setBounds(r.removeFromTop(100));
    pedal[3].setBounds(r.removeFromTop(100));
}
void MainComponent::paint (Graphics& g)
{
    /*
    auto r = getLocalBounds();
    auto row = r.removeFromTop(300);
    int halfWidth = getWidth() / 2.0;
    int halfHeight = getHeight() / 2.0;
    float threeQuarters = (getWidth() / 4) * 3;
     */
    g.setColour(Colours::green);
    g.fillRect(0, 0 , getWidth() / 4, getHeight());
    g.setColour(Colours::purple);
    g.fillRect(getWidth() / 4, 0 , getWidth() / 4, getHeight());
    g.setColour(Colours::blue);
    g.fillRect(getWidth() / 2, 0 , getWidth() / 4, getHeight());
    g.setColour(Colours::yellow);
    g.fillRect(getWidth() - 480, 0 , getWidth() / 4, getHeight());

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
    DBG("COMBO CHANGED");
    if (comboBoxThatHasChanged == &comboBoxs[0])
    {
        audio.setPedalPtr1(comboBoxThatHasChanged->getSelectedId());
        DBG("Pedal Slot 1 changed");
    }
    if (comboBoxThatHasChanged == &comboBoxs[1])
    {
        audio.setPedalPtr2(comboBoxThatHasChanged->getSelectedId());
        DBG("Pedal Slot 2 changed");
    }
        
    if (comboBoxThatHasChanged == &comboBoxs[2])
    {
        audio.setPedalPtr3(comboBoxThatHasChanged->getSelectedId());
        DBG("Pedal Slot 3 changed");
    }
        
    if (comboBoxThatHasChanged == &comboBoxs[3])
    {
        audio.setPedalPtr4(comboBoxThatHasChanged->getSelectedId());
        DBG("Pedal Slot 4 changed");
    }
}
