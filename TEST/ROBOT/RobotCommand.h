#pragma once
#include <stdio.h>

class RobotCommand
{
public:
    RobotCommand()
    {
        deviceType = '?';
        mechType = '?';
    }
    virtual bool validateString() = 0;
    char getDevType();
    char getMechType();
    void setDevType(char c);
    void setMechType(char c);
protected:
    char* commandString;
    bool isNumber(char c);
    char deviceType;
    char mechType;

};
