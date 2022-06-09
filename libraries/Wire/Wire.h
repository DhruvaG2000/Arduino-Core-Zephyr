#pragma once

#include "ArduinoAPI.h"
#include "HardwareI2C.h"

namespace arduino {

class ZephyrI2C : public HardwareI2C
{
    public:
        virtual void begin();
};

}