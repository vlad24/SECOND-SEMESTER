#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "TreeSet.h"

class TreeTester : public QObject
{
    Q_OBJECT
public:
    explicit TreeTester(QObject *parent = 0) : QObject(parent) {}
    
private slots:
    void testEmpty()
    {
        Tree<int> setInt;
        QVERIFY(setInt.isEmpty());
        Tree<char> setChar;
        QVERIFY(setChar.isEmpty());
    }
    void testAddInt()
    {
        Tree<int> setInt;
        setInt.addToTree(5);
        QVERIFY(setInt.root->value == 5);
        setInt.addToTree(10);
        QVERIFY(setInt.root->right->value == 10);
    }
    void testAddChar()
    {
        Tree<char> setChar;
        setChar.addToTree('x');
        QVERIFY(setChar.root->value == 'x');
        setChar.addToTree('y');
        QVERIFY(setChar.root->right->value == 'y');
    }

};
