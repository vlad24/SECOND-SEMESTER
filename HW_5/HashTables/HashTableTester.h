#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "HashTable.h"
#include "PolynomialHasher.h"

class HashTableTester : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTester(QObject *parent = 0):QObject(parent){}
    
private slots:
    void init()
    {
        table = new HashTable;
    }

    void testAddingToTable()
    {
        table->addToHashTable("aabb");
        table->addToHashTable("qt");
        table->addToHashTable("iijj");
    }

    void testExsisting()
    {
        table->addToHashTable("aabb");
        table->addToHashTable("qt");
        table->addToHashTable("iijj");
        QVERIFY(table->isInHashTable("iijj"));
        QVERIFY(table->isInHashTable("aabb"));
        QVERIFY(table->isInHashTable("qt"));
    }
    void testRemovingFromTable()
    {
        table->addToHashTable("anna");
        table->addToHashTable("ivan");
        table->addToHashTable("iijj");
        table->removeFromHashTable("iijj");
        table->removeFromHashTable("oop");
        QVERIFY(table->isInHashTable("anna"));
        QVERIFY(table->isInHashTable("ivan"));
        QVERIFY(!table->isInHashTable("iijj"));
    }

    void testStatistics()
    {
        table->showStatistics();
        table->addToHashTable("ivan");
        table->addToHashTable("oleg");
        table->addToHashTable("anna");
        table->addToHashTable("alla");
        table->addToHashTable("alla");
        table->addToHashTable("alla");
        table->addToHashTable("aabb");
        table->addToHashTable("iijj");
        table->removeFromHashTable("iijj");
        table->removeFromHashTable("oop");
        table->showStatistics();
        table->removeFromHashTable("alla");
        table->showStatistics();
    }

    void testChangingHasher()
    {
        table->addToHashTable("ivan");
        table->addToHashTable("oleg");
        table->addToHashTable("anna");
        table->addToHashTable("alla");
        table->showStatistics();
        Hasher* pHasher = new PolynomialHasher;
        table->setHashFunction(pHasher);
        table->showStatistics();
    }

    void cleanUp()
    {
        delete table;
    }

private:
    HashTable* table;
};
