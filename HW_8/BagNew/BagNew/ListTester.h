#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "SortedList.h"

class ListTester : public QObject
{
    Q_OBJECT
public:
    explicit ListTester(QObject *parent = 0) : QObject(parent){}
        
private slots:
    void testAddingToEmpty()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(5);
        QVERIFY(list->head->value == 5);
        QVERIFY(list->head->reps == 1);
        QVERIFY(list->head->next == NULL);
        delete list;
    }
    void testAddingToTheBeginning()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(5);
        list->add(1);
        QVERIFY(list->head->value == 1);
        QVERIFY(list->head->reps == 1);
        QVERIFY(list->head->next->value == 5);
        delete list;
    }
    void testAddingToTheEnd()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(1);
        list->add(6);
        QVERIFY(list->head->value == 1);
        QVERIFY(list->head->reps == 1);
        QVERIFY(list->head->next->value == 6);
        delete list;
    }
    void testAddingMultiply()
    {
        SortedList<char>* list = new SortedList<char>();
        for (int y = 0; y < 19 ; y++)
            list->add('y');
        QVERIFY(list->head->value == 'y');
        QVERIFY(list->head->reps == 19);
        QVERIFY(list->head->next == NULL);
        delete list;
    }
    void testRemovingFromTheEnd()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(5);
        list->add(4);
        list->remove(5);
        QVERIFY(list->head->value == 4);
        delete list;
    }

    void testRemovingTheOnly()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(5);
        list->remove(5);
        QVERIFY(list->listIsEmpty());
        delete list;
    }
    void testRemovingFromHead()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(5);
        list->add(7);
        list->remove(5);
        QVERIFY(list->head->value = 7);
        delete list;
    }
    void testRemovingMultiplyAdded()
    {
        SortedList<int>* list = new SortedList<int>();
        list->add(5);
        list->add(5);
        list->add(5);
        list->remove(5);
        QVERIFY(list->head->reps == 2);
        delete list;
    }
};
