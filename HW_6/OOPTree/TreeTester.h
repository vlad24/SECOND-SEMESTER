#pragma once
#include "TreeNodeOperand.h"
#include "TreeNodeSign.h"
#include "Tree.h"

#include <QObject>
#include <QtTest/QTest>

class TreeTester : public QObject
{
    Q_OBJECT
public:
    explicit TreeTester(QObject *parent = 0) : QObject(parent){}
    
private slots:
    void testNodeCreation()
    {
        TreeNode* node = new TreeNodeSign('*');
        QVERIFY(node->getValue() == '*');
    }

    void testGetLeft()
    {
        TreeNode* node = new TreeNodeSign('*');
        TreeNode* tmp = node->getLeft();
        QVERIFY(tmp == NULL);
        delete node;
        delete tmp;
    }
    void testEmpty()
    {
        Tree* tree = new Tree();
        bool unexpected = true;
        try
        {
            tree->calculateStringByTree("");
        }
        catch(int)
        {
            QVERIFY(true);
            unexpected = false;
            delete tree;
        }
        if (unexpected)
        {
            QFAIL("Mistake is not seen\n");
        }
    }
    void testCorrectString()
    {
        Tree* tree = new Tree();
        int result = tree->calculateStringByTree("*+213");
        QVERIFY(result == 9);
        delete tree;
    }
    void testIncorrectString()
    {
        Tree* tree = new Tree();
        bool unexpected = true;
        try
        {
            tree->calculateStringByTree("0*+23");
        }
        catch(int)
        {
            QVERIFY(true);
            unexpected = false;
            delete tree;
        }
        if (unexpected)
        {
            QFAIL("Mistake is not seen\n");
        }
    }
    void testLongString()
    {
        Tree* tree = new Tree();
        int result = tree->calculateStringByTree("/+-+*+*+*+*+*+230111111111942");
        QVERIFY(result == 0);
        delete tree;
    }
    void testStringOverloadedByBracketsAndGaps()
    {
        Tree* tree = new Tree();
        int result = tree->calculateStringByTree("((*  ((+ ((    2 1)) 3)) ");
        QVERIFY(result == 9);
        delete tree;
    }
};
