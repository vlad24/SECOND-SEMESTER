#pragma once
#include "RobotCommand.h"
class RobotClass
{
public:
    RobotClass();
    void recieveCommand(RobotCommand *&command);
    void implementCommand(RobotCommand *&command);
};
