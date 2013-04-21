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
    void testWorkingWithCharInIntSet()
    {
        Tree<int> intSet;
        intSet.addToTree(int('v'));
        intSet.removeFromTree('v');
        QVERIFY(intSet.isEmpty());
    }
    void testAddingSeveralTimes()
    {
        Tree<int> intSet;
        intSet.addToTree(1);
        intSet.addToTree(1);
        QVERIFY(intSet.root->left == NULL);
        QVERIFY(intSet.root->right == NULL);
    }

    void testRemovingFromEmpty()
    {
        Tree<int> tree;
        tree.removeFromTree(0);
        QVERIFY(tree.isEmpty());
    }

    void testRemovingUnreal()
    {
        Tree<char> charSet;
        charSet.addToTree('o');
        charSet.removeFromTree('p');
        QVERIFY(charSet.root->value == 'o');
    }

    void testRemovingSeverallyAdded()
    {
        Tree<int> set;
        set.addToTree(2);
        set.addToTree(2);
        set.removeFromTree(2);
        QVERIFY(set.isEmpty());
    }
};
