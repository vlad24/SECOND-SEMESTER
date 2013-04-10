#include "RobotCommand.h"

RobotCommand::RobotCommand()
{
}

bool TurnEngineCommand::isNumber(char c)
{
    return ((c <= '9') && (c >= '0'));
}

char RobotCommand::getDevType()
{
    return deviceType;
}

char RobotCommand::getMechType()
{
    return mechType;
}

void RobotCommand::setDevType(char c)
{
    deviceType = c;
}

void RobotCommand::setMechType(char c)
{
    mechType = c;
}
