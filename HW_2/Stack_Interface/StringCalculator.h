#pragma once
#include "PointerStack.h"

class StringCalculator
{
public:
     int calculateExpression(char string[]);
private:
    bool isNumber(char v) const;
    bool isSign(char v) const;
    int makeOperation(char sign, int argument1, int argument2);
    int polishPriority(char v) const;
    int convertToInt(char v) const;
    void makePolish(char normal[], StackInterface *&stack);
};
