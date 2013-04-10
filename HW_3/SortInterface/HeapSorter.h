#pragma once
#include "SortInterface.h"

class HeapSorter : public SortInterface
{
public:
    void sortArray(int array[], int length);
private:
    /*!
      @brief A function, which puts an element to the heap complying to the heap-rules
      @param array Our heap
      @param parent The index of the element that we want to put in heap
      @param last The index of the last element of our heap
      */
    void putInHeap(int array[], int parent, int last);
    //! A function that creates a heap from an array by putting in heap a half of elements
    void buildHeap(int array[], int last);
};
