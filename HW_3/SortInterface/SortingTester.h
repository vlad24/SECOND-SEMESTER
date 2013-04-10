#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <stdio.h>
#include <stdlib.h>

#include "HeapSorter.h"
#include "QuickSorter.h"
#include "ShellSorter.h"
#include "InsertSorter.h"
#include "BubbleSorter.h"

class SortingTester : public QObject
{
    Q_OBJECT
public:
    explicit SortingTester(QObject *parent = 0) : QObject(parent){}
    
private:
    void fillArrayRandomly(int testArray[], int testLength)
    {
        for (int u = 0; u < testLength; u++)
            testArray[u] = rand() % testLength;
    }
    bool checkResult(int array[], int length)
    {
        bool correct = true;
        for (int i = 1; i < length; i++)
        {
            if (array[i] < array[i - 1])
            {
                correct = false;
                break;
            }
        }
        return correct;
    }
    int testArray[100];
    int testLength;

private slots:
    void init()
    {
        testLength = 100;
        fillArrayRandomly(testArray, testLength);
    }

    void testHeapSorter()
    {
        SortInterface* sorter = new HeapSorter;
        sorter->sortArray(testArray, testLength);
        delete sorter;
        QVERIFY(checkResult(testArray, testLength));
    }

    void testQuickSorter()
    {
        SortInterface* sorter = new QuickSorter;
        sorter->sortArray(testArray, testLength);
        delete sorter;
        QVERIFY(checkResult(testArray, testLength));
    }

    void testShellSorter()
    {
        SortInterface* sorter = new ShellSorter;
        sorter->sortArray(testArray, testLength);
        delete sorter;
        QVERIFY(checkResult(testArray, testLength));
    }

    void testInsertSorter()
    {
        SortInterface* sorter = new InsertSorter;
        sorter->sortArray(testArray, testLength);
        delete sorter;
        QVERIFY(checkResult(testArray, testLength));
    }

    void testBubbleSorter()
    {
        SortInterface* sorter = new BubbleSorter;
        sorter->sortArray(testArray, testLength);
        delete sorter;
        QVERIFY(checkResult(testArray, testLength));
    }
};
