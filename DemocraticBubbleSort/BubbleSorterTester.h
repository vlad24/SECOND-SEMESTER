#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "BubbleSorter.h"
#include "QuadroComparator.h"
#include "StandartComparator.h"


class BubbleSorterTester : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSorterTester(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testSortingInt()
    {
        BubbleSorter<int>* sorter = new BubbleSorter<int>();
        Comparator<int>* comparator = new StandartComparator<int>();
        int array[6] = {2, 5, 1, 0, -6, 0};
        sorter->sortArray(array, 6, comparator);
        bool sortedCorrectly = true;
        for (int i = 0; i < 5; i++)
        {
            sortedCorrectly = sortedCorrectly && !(comparator->firstIsMore(array[i], array[i + 1]));
        }
        delete sorter;
        delete comparator;
        QVERIFY(sortedCorrectly);
    }

    void testSortingChar()
    {
        BubbleSorter<char>* sorter = new BubbleSorter<char>();
        Comparator<char>* comparator = new StandartComparator<char>();
        char array[6] = {'y', 'a', 'n', 'd', 'e', 'x'};
        sorter->sortArray(array, 6, comparator);
        bool sortedCorrectly = true;
        for (int i = 0; i < 5; i++)
        {
            sortedCorrectly = sortedCorrectly && !(comparator->firstIsMore(array[i], array[i + 1]));
        }
        delete sorter;
        delete comparator;
        QVERIFY(sortedCorrectly);
    }

    void testSortingDouble()
    {
        BubbleSorter<double>* sorter = new BubbleSorter<double>();
        Comparator<double>* comparator = new QuadroComparator<double>();
        double array[6] = {1.43, 3.14, -2.71, 2.4, 8.3, -0.9};
        sorter->sortArray(array, 6, comparator);
        bool sortedCorrectly = true;
        for (int i = 0; i < 5; i++)
        {
            sortedCorrectly = sortedCorrectly && !(comparator->firstIsMore(array[i], array[i + 1]));
        }
        delete sorter;
        delete comparator;
        QVERIFY(sortedCorrectly);
    }
};
