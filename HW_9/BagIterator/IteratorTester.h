#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "Iterator.h"

class IteratorTester : public QObject
{
    Q_OBJECT
public:
    explicit IteratorTester(QObject *parent = 0) : QObject(parent) {}
    
private slots:
    void testNexting()
    {
        MultiTreeSet<int>* intSet = new MultiTreeSet<int>();
        intSet->addToTree(2);
        intSet->addToTree(3);
        intSet->addToTree(1);
        Iterator<int>* setIterator = new Iterator<int>(intSet);
        QVERIFY(setIterator->next() == 1);
        QVERIFY(setIterator->next() == 2);
        QVERIFY(setIterator->next() == 3);
        delete setIterator;
    }

    void testHasNexting()
    {
        MultiTreeSet<char>* charSet = new MultiTreeSet<char>();
        charSet->addToTree('r');
        Iterator<char>* setIterator = new Iterator<char>(charSet);
        setIterator->next();
        QVERIFY(!setIterator->hasNext());
        delete setIterator;
    }

    void testAdding()
    {
        MultiTreeSet<char>* charSet = new MultiTreeSet<char>();
        Iterator<char>* setIterator = new Iterator<char>(charSet);
        setIterator->add('r');
        QVERIFY(charSet->exsistsInTree('r'));
        delete setIterator;
    }

    void testRemoving()
    {
        MultiTreeSet<char>* charSet = new MultiTreeSet<char>();
        Iterator<char>* setIterator = new Iterator<char>(charSet);
        charSet->addToTree('u');
        charSet->addToTree('y');
        setIterator->add('r');
        QVERIFY(charSet->exsistsInTree('r'));
        delete setIterator;
    }

    void testTakingFromEmpty()
    {
        MultiTreeSet<int>* intSet = new MultiTreeSet<int>();
        intSet->addToTree(2);
        intSet->addToTree(3);
        intSet->addToTree(1);
        Iterator<int>* setIterator = new Iterator<int>(intSet);
        for (int y = 0; y < 3; y++)
        {
            setIterator->next();
        }
        bool success = false;
        try
        {
            setIterator->next();
        }
        catch (TakingError error)
        {
            success = true;
        }
        QVERIFY(success);
        delete setIterator;
    }
};
