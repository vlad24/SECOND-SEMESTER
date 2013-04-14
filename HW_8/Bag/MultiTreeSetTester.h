#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "MultiTreeSet.h"

class MultiTreeSetTester : public QObject
{
    Q_OBJECT
public:
    explicit MultiTreeSetTester(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testEmpty()
    {
        Tree<int> setInt;
        QVERIFY(setInt.isEmpty());
        Tree<char> setChar;
        QVERIFY(setChar.isEmpty());
    }
    void testAdd()
    {
        Tree<int> setInt;
        setInt.addToTree(4);
        QVERIFY(setInt.root->value == 4);
    }
    void testExsistingAdded()
    {
       Tree<int> setInt;
       setInt.addToTree(0);
       QVERIFY(setInt.exsistsInTree(0));
    }
    void testExsistingUnadded()
    {
       Tree<char> setChar;
       setChar.addToTree('o');
       QVERIFY(!setChar.exsistsInTree('p'));
    }
    void testRemoving()
    {
        Tree<int> setInt;
        setInt.addToTree(4);
        setInt.removeFromTree(4);
        QVERIFY(setInt.isEmpty());
    }
};
