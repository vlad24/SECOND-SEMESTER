#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "Matrix.h"

class MatrixSortTester : public QObject
{
    Q_OBJECT

public:
    explicit MatrixSortTester(QObject *parent = 0): QObject(parent){}
    
private slots:

    void init()
    {
        mat = new Matrix(2, 4);
        QVERIFY(mat->height == 2);
        QCOMPARE(mat->width, 4);
    }

    void testComparison()
    {
        int size = 4;
        int* col1 = new int[size];
        int* col2 = new int[size];
        for (int i = 0; i < size; i++)
            col1[i] = size - i;
        for (int i = 0; i < size; i++)
            col2[i] = i;
        QVERIFY(mat->firstColumnIsMore(col1, col2));
    }

    void testSwapingColumns()
    {
        int size = 4;
        int* col1 = new int[size];
        for (int i = 0; i < size; i++)
            col1[i] = size - i;
        int* col2 = new int[size];
        for (int i = 0; i < size; i++)
            col2[i] = i;
        mat->swapColumns(col1, col2);
        QVERIFY(col1[0] == 0);
    }

    void testSorting()
    {
        mat->fillMatrixRandomly();
        mat->sortColumns();
        for (int i = 1; i < mat->width ; i++)
        {
            QVERIFY(mat->table[i][0] > mat->table[i - 1][0] );
        }
    }

    void cleanUp()
    {
        delete mat;
    }
private:
    Matrix *mat;
};
