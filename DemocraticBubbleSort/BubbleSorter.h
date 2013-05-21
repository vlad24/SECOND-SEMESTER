#pragma once
#include <iostream>
#include "Comparator.h"

using namespace std;

template <typename W>

/*! A template class which enables a user to bubble sort an array
with comparing rules which they set*/

class BubbleSorter
{
public:
    void sortArray(W array[], int size, Comparator<W>* comparator);
};

template <typename W>
void BubbleSorter<W>::sortArray(W array[], int size, Comparator<W> *comparator)
{
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - i; j++)
        {
            if (comparator->firstIsMore(array[j], array[j + 1]))
            {
                W buffer = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buffer;
            }
        }
}
