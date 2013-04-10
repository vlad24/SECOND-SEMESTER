#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "ArrayStack.h"
#include "PointerStack.h"
#include "StringCalculator.h"


class StackTester : public QObject
{
    Q_OBJECT
public:
    explicit StackTester(QObject *parent = 0) : QObject(parent){}
    
private slots:
    void testEmpty()
    {
        ArrayStack* aStack = new ArrayStack;
        PointerStack* pStack = new PointerStack;
        QVERIFY(aStack->firstFree == 0);
        QVERIFY(pStack->isEmpty());
        delete aStack;
        delete pStack;
    }
    void testPush()
    {
        ArrayStack* aStack = new ArrayStack;
        PointerStack* pStack = new PointerStack;
        aStack->push(2);
        pStack->push(2);
        QVERIFY(aStack->firstFree == 1);
        QVERIFY(pStack->top() == 2);
        delete aStack;
        delete pStack;
    }
    void testPop()
    {
        ArrayStack* aStack = new ArrayStack;
        PointerStack* pStack = new PointerStack;
        aStack->push(1);
        pStack->push(1);
        aStack->push(2);
        pStack->push(2);
        QVERIFY(pStack->pop() == 2);
        QVERIFY(aStack->pop() == 2);
        QVERIFY(pStack->pop() == 1);
        QVERIFY(aStack->pop() == 1);
        QVERIFY(pStack->isEmpty());
        QVERIFY(aStack->firstFree == 0);
        delete aStack;
        delete pStack;
    }
    void testClear()
    {
        ArrayStack* aStack = new ArrayStack;
        PointerStack* pStack = new PointerStack;
        aStack->push(1);
        pStack->push(1);
        aStack->push(2);
        pStack->push(2);
        aStack->clear();
        pStack->clear();
        QVERIFY(pStack->isEmpty());
        QVERIFY(aStack->firstFree == 0);
        delete aStack;
        delete pStack;
    }
    void testPrint()
    {
        ArrayStack* aStack = new ArrayStack;
        PointerStack* pStack = new PointerStack;
        aStack->push(1);
        pStack->push(3);
        aStack->push(2);
        pStack->push(4);
        aStack->printStack();
        pStack->printStack();
        delete aStack;
        delete pStack;
    }
    void testCalculatingOnStack()
    {
        StringCalculator* calc = new StringCalculator;
        char s[20] = "(7+(4-2)*(3+1)-3)*2";
        int result = calc->calculateExpression(s);
        QVERIFY(result == 24);
    }
};
