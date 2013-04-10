#include "BubbleSorter.h"

void BubbleSorter::sortArray(int array[], int length)
{
    int last = length - 1;
    for (int i = 1; i <= last; i++)
    {
        for (int j = 0; j <= last - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int buffer = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buffer;
            }
        }
    }
}
