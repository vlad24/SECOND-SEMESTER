#include "HeapSorter.h"

void HeapSorter::putInHeap(int array[], int parent, int last)
{
    int largestKid = parent;
    int leftKid = 2 * parent + 1 ;
    int rightKid = 2 * parent + 2 ;
    if (rightKid <= last) // right kid exsists
    {
        if ((array[parent] < array[leftKid]) || (array[parent] < array[rightKid])) //Heap is incorrect
        {
            largestKid = leftKid;
            if (array[rightKid] > array[leftKid])
                largestKid = rightKid;

            int tmp = array[largestKid];
            array[largestKid] = array[parent];
            array[parent] = tmp;

            putInHeap(array, largestKid, last) ;
        }
    }
    else
    {
        if (rightKid == (last + 1)) // It means that leftKid == last => leftKid exsists
        {
            if (array[parent] < array[leftKid])
            {
                int tmp = array[leftKid];
                array[leftKid] = array[parent];
                array[parent] = tmp;
            }
        }
    }

 }

void HeapSorter::buildHeap(int array[], int last)
{
    int middle = 0;
    if (last % 2 == 0)
        middle = last / 2 - 1;
    else
        middle = last / 2;

    for (int upperElement = middle; upperElement >= 0; upperElement--)
        putInHeap(array, upperElement, last);
}

void HeapSorter::sortArray(int array[], int length)
{
    int last = length - 1;
    buildHeap(array, last);
    for (int i = 0; i < last; i++)
    {
        int tmp = array[0];
        array[0] = array[last - i];
        array[last - i] = tmp;
        putInHeap(array, 0, last - i - 1);
    }
}
