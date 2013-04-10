#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "List.h"

class ListTester : public QObject
{
    Q_OBJECT
public:
    explicit ListTester(QObject *parent = 0) : QObject(parent){}
    
signals:
    
private slots:
    void init()
    {
        testedList = new List;
    }
    void testAdding()
    {
        testedList->add("1st");
        testedList->add("2st");
        testedList->add("1st");
        testedList->add("2st");
        testedList->add("3st");
        QVERIFY(testedList->getLength() == 3);
    }

    void testExsisting()
    {
        testedList->add("1st");
        testedList->add("2nd");
        QVERIFY(testedList->stringExsists("2nd"));
        QVERIFY(!(testedList->stringExsists("3rd")));
        testedList->add("3rd");
        QVERIFY(testedList->stringExsists("3rd"));
    }

    void testRemovingFromMidd()
    {
        testedList->add("1st");
        testedList->add("2nd");
        testedList->add("3rd");
        testedList->add("4th");
        testedList->add("5th");
        testedList->remove("3rd");
        testedList->remove("2nd");
        testedList->print();
    }

    void testRemovingTheFirst()
    {
        testedList->add("1st");
        testedList->add("2nd");
        testedList->add("3rd");
        testedList->add("1st");
        testedList->add("4th");
        testedList->remove("1st");
        testedList->remove("2nd");
        testedList->print();
    }

    void testRemovingUnreal()
    {
        testedList->remove("1st");
        testedList->add("2nd");
        testedList->remove("1st");
        testedList->print();
    }
    void testSizeChanging()
    {
        QVERIFY(testedList->getLength() == 0);

        testedList->add("1st");
        QVERIFY(testedList->getLength() == 1);

        testedList->add("2nd");
        QVERIFY(testedList->getLength() == 2);

        testedList->add("1st");
        QVERIFY(testedList->getLength() == 2);

        testedList->remove("1st");
        QVERIFY(testedList->getLength() == 1);

        testedList->remove("2nd");
        QVERIFY(testedList->getLength() == 0);

        testedList->remove("5th");
        QVERIFY(testedList->getLength() == 0);
 }

    void cleanUp()
    {
        delete testedList;
    }
private:
    List* testedList;
};
