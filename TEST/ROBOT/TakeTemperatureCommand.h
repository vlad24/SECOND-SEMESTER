#pragma once
#include "RobotCommand.h"

class TakeTemperatureCommand : public RobotCommand
{
public:
    TakeTemperatureCommand(char* str);
    bool validateString();
    int temperature();
};

