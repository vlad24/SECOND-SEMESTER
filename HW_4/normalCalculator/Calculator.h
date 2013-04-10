#pragma once
#include <qstring.h>

class Calculator
{
public:
    //! A function that can do basic arithmetic
    QString makeOperation(const QString &argumentOne, const QString &argumentTwo, const QString &sign);
};
