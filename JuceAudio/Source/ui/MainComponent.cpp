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
}
void MainComponent::paint (Graphics& g)
{
    auto r = getLocalBounds();
    auto row = r.removeFromTop(300);
    int halfWidth = getWidth() / 2.0;
    int halfHeight = getHeight() / 2.0;
    float threeQuarters = (getWidth() / 4) * 3;
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
