//
//  Compressor.hpp
//  SDA Pedal Project - App
//
//  Created by Bevan Salter on 12/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include <JuceHeader.h>
#include "/Users/bevansalter/Desktop/SDA 2021/SDA Pedal Project/JuceAudio/Source/audio/Pedal.hpp"


class Compressor :   public Pedal
{
public:
    Compressor();
    ~Compressor();
    float process(float input) override;
    void setParameter1(float input) override;
    void setParameter2(float input) override;
    void setParameter3(float input) override;
    void setParameter4(float input) override;
    void setParameter5(float input) override;
private:
    
};
