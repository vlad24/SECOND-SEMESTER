#pragma once

#include <QObject>
#include <QTest>
#include "PointerList.h"
#include "AddingError.h"
#include "DeletingError.h"

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(QObject *parent = 0) : QObject(parent){}
private slots:
    void testAddingFirst()
    {
        PointerList* list = new PointerList();
        try
        {
            list->add(1);
            list->add(4);
        }
        catch (AddingError error)
        {
            QFAIL("");
        }
    }
    void testDeletingExsisting()
    {
        PointerList* list = new PointerList();
        try
        {
            list->add(1);
            list->remove(1);
        }
        catch (DeletingError error)
        {
            QFAIL("");
        }
        delete list;
    }
    void testAddingExsisting()
    {
        PointerList* list = new PointerList();
        bool goodJob = false;
        try
        {
            list->add(1);
            list->add(4);
            list->add(1);
        }
        catch (AddingError error)
        {
           goodJob = true;
        }
        QVERIFY(goodJob);
    }
    void testRemoveUnexsisting()
    {
        PointerList* list = new PointerList();
        bool goodJob = false;
        try
        {
            list->add(1);
            list->add(4);
            list->remove(6);
        }
        catch (DeletingError error)
        {
           goodJob = true;
        }
        QVERIFY(goodJob);
    }
};
