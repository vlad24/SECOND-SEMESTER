#include <stdio.h>
#include <stdlib.h>
#include <QTime>
#include "SortBattler.h"
#include "HeapSorter.h"
#include "QuickSorter.h"
#include "ShellSorter.h"
#include "InsertSorter.h"
#include "BubbleSorter.h"

void SortBattler::fillArrayRandomly(int testArray[], int testLength)
{
    for (int u = 0; u < testLength; u++)
        testArray[u] = rand() % testLength;
}

void SortBattler::printTime()
{
    QTime timer;
    timer = timer.currentTime();
    printf("%d:%d:%d\n", timer.hour(), timer.minute(), timer.second());
}

void SortBattler::sortsTimeBattle(int testLength)
{
    SortInterface* hSorter = new HeapSorter;
    SortInterface* qSorter = new QuickSorter;
    SortInterface* sSorter = new ShellSorter;
    SortInterface* iSorter = new InsertSorter;
    SortInterface* bSorter = new BubbleSorter;
    int* battleArray = new int[testLength];

    printf("Integer Array of %d elements will be now sorted\n", testLength);
    printf("Heap:\n");
    printTime();
    hSorter->sortArray(battleArray, testLength);
    printTime();
    printf("---\n");

    fillArrayRandomly(battleArray, testLength);

    printf("Quick:\n");
    printTime();
    qSorter->sortArray(battleArray, testLength);
    printTime();
    printf("---\n");

    fillArrayRandomly(battleArray, testLength);

    printf("Shell:\n");
    printTime();
    sSorter->sortArray(battleArray, testLength);
    printTime();
    printf("---\n");

    fillArrayRandomly(battleArray, testLength);

    printf("Insert:\n");
    printTime();
    iSorter->sortArray(battleArray, testLength);
    printTime();
    printf("---\n");

    fillArrayRandomly(battleArray, testLength);

    printf("Bubble:\n");
    printTime();
    bSorter->sortArray(battleArray, testLength);
    printTime();
    printf("---\n");

    delete hSorter;
    delete qSorter;
    delete iSorter;
    delete sSorter;
    delete bSorter;
}
