#pragma once
#include "RobotCommand.h"
class TurnEngineCommand : public RobotCommand
{
public:
    TurnEngineCommand(char* str);
    bool validateString(char *string);
};
