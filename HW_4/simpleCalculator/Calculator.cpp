#include "Calculator.h"
#include <limits.h>

double Calculator::makeOperation(int argument1, int argument2, QString sign)
{
    char operation = sign.at(0).toAscii();
    switch (operation)
    {
    case ('-') :
    {
        return argument1 - argument2;
    }
    case ('+') :
    {
        return argument1 + argument2;
    }
    case ('*') :
    {
        return argument1 * argument2 ;
    }
    case ('/') :
    {
        if (argument2 != 0)
            return (double(argument1) / double(argument2));
        else
            return INT_MAX ;
    }
    }
}
