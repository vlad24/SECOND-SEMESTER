#include "InsertSorter.h"

void InsertSorter::sortArray(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (array[j] < array[j - 1])
        {
            int buffer = array[j];
            array[j] = array[j - 1];
            array[j - 1] = buffer;
            j--;
            if (j == 0)
                break;
        }
    }
}
