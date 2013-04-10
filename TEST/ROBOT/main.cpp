#include <stdio.h>
#include "RobotClass.h"
#include "TurnEngineCommand.h"
#include "TakeTemperatureCommand.h"


int main()
{
    RobotClass* robot = new RobotClass();
    printf("Enter the command\n");
    char userCommandString[100] = {};
    scanf("%s", &userCommandString);
    switch(userCommandString[1])
    {
    case 'T':
    {
        RobotCommand* command = new TurnEngineCommand(userCommandString);
        if (command->validateString(command))
        {
            robot->recieveCommand(command);
        }
        else
        {
            printf("Error\n");
        }
    }
    case 'C':
    {
        RobotCommand* command = new TakeTemperatureCommand(userCommandString);
    }
    }
    return 0;
}

