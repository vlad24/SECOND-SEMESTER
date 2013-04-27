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

    void testRemovingLeaf()
    {
        Tree<int> set;
        set.addToTree(1);
        set.addToTree(2);
        set.addToTree(4);
        set.removeFromTree(4);
        QVERIFY(set.root->right->right == NULL);
    }

    void testRemoveWithOneChild()
    {
        Tree<int> set;
        set.addToTree(1);
        set.addToTree(0);
        set.addToTree(2);
        set.addToTree(6);
        set.removeFromTree(2);
        QVERIFY(set.root->right->value == 6);
    }

    void testPoppingLeftInCaseOfTwoChilds()
    {
        Tree<int> set;
        set.addToTree(0);
        set.addToTree(5);
        set.addToTree(1);
        set.addToTree(9);
        set.addToTree(8);
        set.addToTree(7);
        int leftChild = set.popMostLeftValue(set.root->right->right);
        QVERIFY(leftChild == 7);
    }

    void testRemovingTwoChildsCase()
    {
        Tree<int> set;
        set.addToTree(0);
        set.addToTree(5);
        set.addToTree(1);
        set.addToTree(9);
        set.addToTree(8);
        set.addToTree(7);
        set.removeFromTree(5);
        QVERIFY(set.root->right->value == 7);
    }

    void testRemovingWhenNoMostLeftValue()
    {
        Tree<char> set;
        set.addToTree('a');
        set.addToTree('e');
        set.addToTree('d');
        set.addToTree('x');
        char leftChild = set.popMostLeftValue(set.root->right->right);
        QVERIFY (leftChild == 'x');
    }
};
