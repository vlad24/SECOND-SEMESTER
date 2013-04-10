#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "PointerList.h"
#include "ArrayList.h"
class ListTester : public QObject
{
    Q_OBJECT
public:
    explicit ListTester(QObject *parent = 0) : QObject(parent){}
    
private slots:
    void init()
    {

    }

    void testEmpty()
    {
        PointerList* pList = new PointerList();
        ArrayList* aList = new ArrayList();
        QVERIFY(pList->listIsEmpty());
        QVERIFY(aList->firstFree == 0 );
        QVERIFY(aList->capacity == 575 );
        delete pList;
        delete aList;
    }

    void testAdding()
    {
        PointerList* pList = new PointerList();
        ArrayList* aList = new ArrayList();
        pList->add(1);
        pList->add(2);
        pList->add(3);
        pList->add(4);
        aList->add(1);
        aList->add(2);
        aList->add(3);
        aList->add(4);
        QVERIFY(aList->firstFree == 4);
        QVERIFY(!(pList->listIsEmpty()));
        pList->print();
        aList->print();
        delete pList;
        delete aList;
    }
    void testRemoving()
    {
        PointerList* pList = new PointerList();
        ArrayList* aList = new ArrayList();
        pList->add(1);
        pList->add(2);

        aList->add(1);
        aList->add(2);

        pList->print();
        aList->print();

        printf("Deleting 1 and 5 in lists :\n");
        pList->remove(1);
        pList->remove(5);

        aList->remove(1);
        aList->remove(5);

        QVERIFY(aList->firstFree == 1);
        QVERIFY(!(pList->listIsEmpty()));
        printf("Left:\n");
        pList->print();
        aList->print();

        delete pList;
        delete aList;
    }

    void cleanUp()
    {

    }
};
