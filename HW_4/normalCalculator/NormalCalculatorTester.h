#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <QString>
#include <QDebug>
#include <stdlib.h>
#include "Calculator.h"

class NormalCalculatorTester : public QObject
{
    Q_OBJECT
public:
    explicit NormalCalculatorTester(QObject *parent = 0): QObject(parent){}

private slots:
    void init()
    {
       testCalculator = new Calculator;
    }
    void testSubtraction()
    {
        QString argument1 = "5443.6";
        QString argument2 = "43.5";
        QString result = testCalculator->makeOperation(argument1, argument2, "-");
        QVERIFY(result == "5400.1");
    }
    void testSumming()
    {
        QString argument1 = "5443.6";
        QString argument2 = "43.5";
        QString result = testCalculator->makeOperation(argument1, argument2, "+");
        QVERIFY(result == "5487.1");
    }
    void testMultiplication()
    {
        QString argument1 = "24.0";
        QString argument2 = "52.5";
        QString result = testCalculator->makeOperation(argument1, argument2, "*");
        QVERIFY(result == "1260");
    }
    void testDivisionByNonZero()
    {
        QString argument1 = "23";
        QString argument2 = "13";
        QString result = testCalculator->makeOperation(argument1, argument2, "/");
        QVERIFY(result == "1.7692");
    }
    void testDivisionByZero()
    {
        QString argument1 = "3244343343434";
        QString argument2 = "0";
        QString result = testCalculator->makeOperation(argument1, argument2, "/");
        QVERIFY(result == "Division by zero");
    }
    void cleanUp()
    {
        delete testCalculator;
    }

private:
    Calculator* testCalculator;
    
};
