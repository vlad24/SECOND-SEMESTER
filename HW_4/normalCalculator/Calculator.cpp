#include "Calculator.h"
#include <QDebug>

QString Calculator::makeOperation(const QString &number1, const QString &number2, const QString &sign)
{
    char operation = sign.at(0).toAscii();
    bool noErrors1 = true;
    bool noErrors2 = true;
    double argument1 = number1.toDouble(&noErrors1);
    double argument2 = number2.toDouble(&noErrors2);
    double tmp = 0;
    QString result = "";
    if (noErrors1 && noErrors2)
    {
        switch (operation)
        {
        case ('-') :
        {
            tmp = argument1 - argument2;
            result = QString::number(tmp, 'f');
            break;
        }
        case ('+') :
        {
            tmp = argument1 + argument2;
            result = QString::number(tmp, 'f');
            break;
        }
        case ('*') :
        {
            tmp = argument1 * argument2;
            result = QString::number(tmp, 'f');
            break;
        }
        case ('/') :
        {
            if (argument2 != 0)
            {
                tmp = argument1 / argument2;
                result = QString::number(tmp, 'f');
                break;
            }
            else
            {
                result = "Division by zero";
            }
        }
        }
    }
    else
    {
        result = "Incorrect operand(s) ";
    }
    return result;
}
