#pragma once

#include <QObject>
#include <QTest>
#include "UniqueList.h"
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
        UniqueList* list = new UniqueList();
        try
        {
            list->addCarefully(1);
            list->addCarefully(4);
        }
        catch (AddingError error)
        {
            QFAIL("");
        }
        delete list;
    }
    void testDeletingExsisting()
    {
        UniqueList* list = new UniqueList();
        try
        {
            list->addCarefully(1);
            list->removeCarefully(1);
        }
        catch (DeletingError error)
        {
            QFAIL("");
        }
        delete list;
    }
    void testAddingExsisting()
    {
        UniqueList* list = new UniqueList();
        bool goodJob = false;
        try
        {
            list->addCarefully(1);
            list->addCarefully(4);
            list->addCarefully(1);
        }
        catch (AddingError error)
        {
           goodJob = true;
        }
        QVERIFY(goodJob);
    }
    void testRemoveUnexsisting()
    {
        UniqueList* list = new UniqueList();
        bool goodJob = false;
        try
        {
            list->addCarefully(1);
            list->addCarefully(4);
            list->removeCarefully(6);
        }
        catch (DeletingError error)
        {
           goodJob = true;
        }
        QVERIFY(goodJob);
    }
};
