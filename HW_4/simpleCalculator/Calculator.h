#pragma once
#include <qstring.h>

class Calculator
{
public:
    //! A function that can sum, subtract, multiply int numbers and can divide in double
    double makeOperation(int argumentOne, int argumentTwo, QString sign);
};
