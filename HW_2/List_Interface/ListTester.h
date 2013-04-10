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
    void testEmptyPointer()
    {
        PointerList* pList = new PointerList();
        QVERIFY(pList->listIsEmpty());
        delete pList;
    }

    void testEmptyArray()
    {
        ArrayList* aList = new ArrayList();
        QVERIFY(aList->firstFree == 0 );
        QVERIFY(aList->capacity == 575 );
        delete aList;
    }

    void testAddingPointer()
    {
        PointerList* pList = new PointerList();
        pList->add(1);
        QVERIFY(!(pList->listIsEmpty()));
        pList->add(2);
        QVERIFY(pList->head->next->value == 2);
        delete pList;
    }
    void testAddingArray()
    {
        ArrayList* aList = new ArrayList();
        aList->add(7);
        QVERIFY(aList->array[0] == 7);
        aList->add(8);
        QVERIFY(aList->array[1] == 8);
        delete aList;
    }
    void testRemovingPointer()
    {
        PointerList* pList = new PointerList();
        pList->add(1);
        pList->add(2);
        pList->remove(1);
        QVERIFY(pList->head->value == 2);
        QVERIFY(!(pList->listIsEmpty()));
        delete pList;
    }
    void testRemovingArray()
    {
        ArrayList* aList = new ArrayList();
        aList->add(1);
        aList->add(2);
        aList->remove(1);
        QVERIFY(aList->array[0] == 2);
        delete aList;
    }
};
