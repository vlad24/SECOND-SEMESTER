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
        MultiTreeSet<int> setInt;
        QVERIFY(setInt.isEmpty());
        MultiTreeSet<char> setChar;
        QVERIFY(setChar.isEmpty());
    }

    void testaddToTree()
    {
        MultiTreeSet<int> setInt;
        setInt.addToTree(4);
        QVERIFY(setInt.root->value == 4);
    }

    void testExsistingAdded()
    {
       MultiTreeSet<int> setInt;
       setInt.addToTree(0);
       QVERIFY(setInt.exsistsInTree(0));
    }

    void testExsistingUnadded()
    {
       MultiTreeSet<char> setChar;
       setChar.addToTree('o');
       QVERIFY(!setChar.exsistsInTree('p'));
    }

    void testRemoving()
    {
        MultiTreeSet<char> setInt;
        setInt.addToTree('r');
        setInt.removeFromTree('r');
        QVERIFY(setInt.root == NULL);
    }

    void testCounting()
    {
        MultiTreeSet<int> setInt;
        setInt.addToTree(4);
        setInt.addToTree(4);
        setInt.removeFromTree(4);
        QVERIFY(setInt.root->value == 4);
        setInt.removeFromTree(4);
        QVERIFY(setInt.root == NULL);
    }
};
