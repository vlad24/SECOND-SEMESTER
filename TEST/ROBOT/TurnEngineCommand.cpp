#include "TurnEngineCommand.h"

TurnEngineCommand::TurnEngineCommand(char *str)
{
    setMType('B');
    setDevType('T');
    commandString = str;
}

bool TurnEngineCommand::validateString(char* string)
{
    return ((string[0] == 'U') && (string[1] == 'T') && (isNumber(string[2])));
}
