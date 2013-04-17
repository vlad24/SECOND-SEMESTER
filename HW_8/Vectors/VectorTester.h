#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "Vector.h"

class VectorTester : public QObject
{
    Q_OBJECT
public:
    explicit VectorTester(QObject *parent = 0): QObject(parent) {}

private slots:

    void testSum()
    {
        Vector* vector1 = new Vector(1, 2, 3);
        Vector* vector2 = new Vector(*vector1);
        Vector* vector3 = new Vector(*(vector1->sumWithAnotherVector(vector2)));
        QVERIFY(vector3->abscissa == 2);
        QVERIFY(vector3->ordinate == 4);
        QVERIFY(vector3->applicate == 6);
        delete vector1;
        delete vector2;
        delete vector3;
    }

    void testSubtraction()
    {
        Vector* vector1 = new Vector(1, 2, 3);
        Vector* vector2 = new Vector(-1, -2, -3);
        Vector* vector3 = new Vector(*(vector1->subtractAnotherVector(vector2)));
        QVERIFY(vector3->abscissa == 2);
        QVERIFY(vector3->ordinate == 4);
        QVERIFY(vector3->applicate == 6);
        delete vector1;
        delete vector2;
        delete vector3;
    }

    void testZero()
    {
        Vector* vector1 = new Vector(0, 0, 0);
        QVERIFY(vector1->isZero());
        delete vector1;
    }

    void testScalarProduct()
    {
        Vector* vector1 = new Vector(1, 2, 3);
        Vector* vector2 = new Vector(*vector1);
        int product = vector1->scalarProductWithAnotherVector(vector2);
        QVERIFY(product == 14);
        delete vector1;
        delete vector2;
    }
    
};
