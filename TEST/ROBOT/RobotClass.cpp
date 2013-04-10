#include "RobotClass.h"

RobotClass::RobotClass()
{
}

void RobotClass::recieveCommand(RobotCommand *&command)
{
    if (command->deviceType == 'U')
    {
        printf("USB ACTIVATED\n");
    }
    else if (command->deviceType == 'B')
    {
        printf("Bluetooth activated\n");
    }

    implementCommand(command);


}
void RobotClass::implementCommand(RobotCommand *&command)
{
    printf("%s. Done", command->commandString);
}
