#include "TakeTemperatureCommand.h"


TakeTemperatureCommand::TakeTemperatureCommand(char *str)
{
    setDevType('C');
    setMechType('U');
    commandString = str;
}

bool TakeTemperatureCommand::validateString()
{
    return (commandString[0] == 'U') && (commandString[1] == 'C') && (isNumber(s[2]));
}

int TakeTemperatureCommand::temperature()
{
    return 0;
}

