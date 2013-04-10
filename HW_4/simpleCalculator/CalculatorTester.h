#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <QDebug>
#include <stdlib.h>
#include <limits.h>
#include "Calculator.h"

class CalculatorTester : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTester(QObject *parent = 0): QObject(parent) {}
    
private slots:
    void init()
    {
        testCalculator = new Calculator;
    }

    void testSubtraction()
    {
        int argument1 = rand() % 1000;
        int argument2 = rand() % 1000;
        int result = argument1 - argument2;
        int testResult = testCalculator->makeOperation(argument1, argument2, "-");
        QVERIFY(testResult == result);
    }
    void testMultiplication()
    {
        int argument1 = rand() % 1000;
        int argument2 = rand() % 1000;
        int result = argument1 * argument2;
        int testResult = testCalculator->makeOperation(argument1, argument2, "*");
        QVERIFY(testResult == result);
    }
    void testSumming()
    {
        int argument1 = rand() % 1000;
        int argument2 = rand() % 1000;
        int result = argument1 + argument2;
        int testResult = testCalculator->makeOperation(argument1, argument2, "+");
        QVERIFY(testResult == result);
    }
    void testDivisionByNonZero()
    {
        int argument1 = rand() % 1000;
        int argument2 = rand() % 1000;
        argument2 = argument2 * argument2 + 1;
        double result = double(argument1) / double(argument2);
        double testResult = testCalculator->makeOperation(argument1, argument2, "/");
        QVERIFY((testResult - result <= 0.000001)&&(testResult - result >= -0.000001));
    }
    void testDivisionByZero()
    {
        int argument1 = rand() % 1000;
        int argument2 = 0;
        double testResult = testCalculator->makeOperation(argument1, argument2, "/");
        QVERIFY(testResult == INT_MAX);
    }

    void cleanUp()
    {
        delete testCalculator;
    }
private:
   Calculator* testCalculator;
};
