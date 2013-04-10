#include <stdio.h>
#include <stdlib.h>
#include "SortingTester.h"
#include "SortBattler.h"
#include "HeapSorter.h"
#include "QuickSorter.h"
#include "ShellSorter.h"
#include "InsertSorter.h"
#include "BubbleSorter.h"
enum userChoices
{
    sorting,
    observing,
    heapSortSelection,
    quickSortSelection,
    shellSortSelection,
    insertSortSelection,
    bubbleSortSelection
};

// A variable that wil be used for setting the size of the array, which we will be working with
const int size = 576;

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    SortingTester tester;
    QTest::qExec(&tester);
    printf("What now?\n");
    printf("0 - sort your array\n");
    printf("1 - observe sorting times\n");
    int answer1 = 0;
    scanf("%d", &answer1);

    if (answer1 == sorting)
    {
        int buffer = 0;
        int i = 0;
        int array[size] = {};
        printf("Enter your int array in the string with gaps, finish with -100\n");

        while (true)
        {
            scanf("%d", &buffer);
            if (buffer == -100)
                break;
            else
                array[i++] = buffer;
        }
        // Now i shows the next index after the last read, i equals the length of the array
        int length = i;
        printf("Your array:\n");
        printArray(array, length);
        printf("What now?\n");
        printf("2 - HeapSort my array up\n");
        printf("3 - QuickSort my array up\n");
        printf("4 - ShellSort my array up\n");
        printf("5 - InsertSort my array up\n");
        printf("6 - BubbleSort my array up\n");
        int answer2 = 0;
        SortInterface* sorter;
        scanf("%d", &answer2);
        switch (answer2)
        {
        case heapSortSelection:
        {
            sorter = new HeapSorter();
            sorter->sortArray(array, length);
            printArray(array, length);
            delete sorter;
            break;
        }
        case quickSortSelection:
        {
            sorter = new QuickSorter();
            sorter->sortArray(array, length);
            printArray(array, length);
            delete sorter;
            break;
        }
        case shellSortSelection:
        {
            sorter = new ShellSorter();
            sorter->sortArray(array, length);
            printArray(array, length);
            delete sorter;
            break;
        }
        case insertSortSelection:
        {
            sorter = new InsertSorter();
            sorter->sortArray(array, length);
            printArray(array, length);
            delete sorter;
            break;
        }
        case bubbleSortSelection:
        {
            sorter = new BubbleSorter();
            sorter->sortArray(array, length);
            printArray(array, length);
            delete sorter;
            break;
        }
        default:
        {
            printf("error\n");
        }
        }
    }
    else if (answer1 == observing)
    {
        SortBattler* battler = new SortBattler();
        printf("Now you are going to feel the difference between sorting algorithms\n");
        printf("An L-sized array will be generated for each sort algorithm\n");
        printf("Enter L:\n");
        int tmpLength = 1;
        scanf("%d", &tmpLength);
        if (tmpLength > 0)
        {
            battler->sortsTimeBattle(tmpLength);
        }
        else
        {
            printf("Error\n");
        }
        delete battler;
    }
}
