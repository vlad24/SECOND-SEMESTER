#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <QDebug>
#include "CommonHasher.h"
#include "PolynomialHasher.h"
#include "BaseHasher.h"

class HasherTester : public QObject
{
    Q_OBJECT
public:
    explicit HasherTester(QObject *parent = 0) : QObject(parent){}

private slots:
    void init()
    {
        cHasher = new CommonHasher;
        pHasher = new PolynomialHasher;
        bHasher = new BaseHasher;
    }

    void testCommonHasher()
    {
        char* s = "abc";
        int hash = cHasher->hashFunction(s);
        QVERIFY(hash == 5);
    }

    void testCommonHasherLongStrings()
    {
         char* s = "abcdefghijklmnopq";
         int hash = cHasher->hashFunction(s);
         QVERIFY(hash == (int('q') - 8) % 31);
    }

    void testCommonHasherSimilarSrtings()
    {
        char* s1 = "bbbb";
        char* s2 = "iiii";
        int hash1 = cHasher->hashFunction(s1);
        int hash2 = cHasher->hashFunction(s2);
        QVERIFY(hash1 == hash2);
    }

    void testPolynomialHasher()
    {
        char* s = "ab";
        int hash = pHasher->hashFunction(s);
        QVERIFY(hash == (97 + 5 * 98) % 31);
    }

    void testPolynomialHasherLongStrings()
    {
        char* s = "abcdefggijklmnopq";
        int hash = pHasher->hashFunction(s);
        QVERIFY((hash >= 0) && (hash < 31));
    }

    void testBaseHasher()
    {
        char* s = "ab";
        int hash = bHasher->hashFunction(s);
        QVERIFY(hash == 2);
    }
    void testBaseHasherLongString()
    {
        char* s = "abcdefghijklmnopqstuxwxyz";
        int hash = bHasher->hashFunction(s);
        QVERIFY((hash >= 0) && (hash < 31));
    }

    void cleanUp()
    {
        delete cHasher;
        delete pHasher;
        delete bHasher;
    }
private:
    Hasher* cHasher;
    Hasher* pHasher;
    Hasher* bHasher;
};
