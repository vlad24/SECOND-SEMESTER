#include "SortInterface.h"
#include "QuickSorter.h"

int QuickSorter::putElement(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int middle = (i + j) / 2;
    while (i < j)
    {
        // The left border moves right untill we have an element that is more than given
        while ((array[i] <= array[middle]) && (i < middle))
            i++;
        // The right border moves left untill we have an element that is less than given
        while ((array[j] >= array[middle]) && (j > middle))
            j--;

        // Swaping the elements
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;

        /*
            Accounting the fact that our element could move to a new place
            if some border has reached its position
        */
        if (i == middle)
            middle = j;
        else if (j == middle )
            middle = i;
    }
    return middle ;
}

void QuickSorter::qSort(int array[], int left, int right)
{
    if (left < right)
        {
            int correctPosition = putElement(array, left, right);
            qSort(array, left, correctPosition - 1);
            qSort(array, correctPosition + 1, right);
        }
}

void QuickSorter:: sortArray(int array[], int length)
{
    qSort(array, 0, length - 1);
}
