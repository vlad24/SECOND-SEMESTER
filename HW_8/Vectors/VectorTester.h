#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "Vector.h"

class VectorTester : public QObject
{
    Q_OBJECT
public:
    explicit VectorTester(QObject *parent = 0) : QObject(parent){}

private slots:
    void testSumming()
    {
        int coordinatesSet1[3] = {7,7,7};
        int coordinatesSet2[3] = {0,0,1};
        Vector<int> vector1 = Vector<int>(coordinatesSet1, 3);
        Vector<int> vector2 = Vector<int>(coordinatesSet2, 3);
        Vector<int> vector3 = vector1 + vector2;
        QVERIFY(vector3.coordinates[0] == 7);
        QVERIFY(vector3.coordinates[1] == 7);
        QVERIFY(vector3.coordinates[2] == 8);
    }
    void testSubtraction()
    {
        char coordinatesSet1[3] = {'a','a','a'};
        char coordinatesSet2[3] = {'q','z','q'};
        Vector<char> vector1 = Vector<char>(coordinatesSet1, 3);
        Vector<char> vector2 = Vector<char>(coordinatesSet2, 3);
        Vector<char> vector3 = vector2 - vector1;
        QVERIFY(vector3.coordinates[0] == char(16));
        QVERIFY(vector3.coordinates[1] == char(25));
        QVERIFY(vector3.coordinates[2] == char(16));
    }
    void testMultiplication()
    {
        double coordinatesSet1[4] = {1.5, 2.5, 0, 1};
        double coordinatesSet2[4] = {0, 4, 8.6543, 2};
        Vector<double> vector1 = Vector<double>(coordinatesSet1, 4);
        Vector<double> vector2 = Vector<double>(coordinatesSet2, 4);
        double product = vector2 * vector1;
        QVERIFY(int(product) == 12);
    }
    void testZero()
    {
        char coordinatesSet1[3] = {'o','o'};
        Vector<char> vector1 = Vector<char>(coordinatesSet1, 2);
        QVERIFY(vector1.isZero('o'));
    }
    void testDimMistake()
    {
        bool success = false;
        int coordinatesSet1[3] = {7, 7, 7};
        int coordinatesSet2[4] = {0, 0, 1, 1};
        Vector<int> vector1 = Vector<int>(coordinatesSet1, 3);
        Vector<int> vector2 =  Vector<int>(coordinatesSet2, 4);
        try
        {
            Vector<int> errorVector = vector1 + vector2;
        }
        catch(DimError error)
        {
            success = true;
        }
         QVERIFY(success);
    }
};
