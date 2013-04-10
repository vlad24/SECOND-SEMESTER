#pragma once
#include "SortInterface.h"

class QuickSorter : public SortInterface
{
public:
    void sortArray(int array[], int length);
private:
    /*!
        A function, which puts element at his "right" place in the array and returns its position
        It puts all elements, that are more than given to the right and less to the left
      */
    int putElement(int array[], int left, int right);
    void qSort(int array[], int left, int right);
};
