#include "ArrayList.h"
#include <limits.h>
#include <stdio.h>

const
int size = 576;

ArrayList::ArrayList()
{
    array = new int[size];
    capacity = size - 1;
    firstFree = 0;
    for (int i = 0; i <= capacity; i++)
    {
        array[i] = INT_MIN;
    }
}

void ArrayList::add(int j)
{
    if (firstFree <= capacity)
    {
        array[firstFree] = j;
        firstFree++;
    }
    else
    {
        int doubleCapacity = (capacity + 1) * 2;
        int* array2 = new int[doubleCapacity];
        for (int i = 0; i <= capacity; i++)
        {
            array2[i] = array[i];
        }
        array2[capacity + 1] = j;
        delete[] array;

        firstFree = capacity + 2;
        capacity = doubleCapacity - 1;
        array = array2;
    }

}

void ArrayList::remove(int value)
{
    int number = 0;
    while ((number < firstFree) && (array[number] != value))
    {
        ++number;
    }
    if (number == firstFree)
    {
        printf("%d is not found\n", value);
    }
    else
    {
        for (int i = number; i <= capacity - 1; i++)
        {
            array[i] = array[i + 1];
        }
        array[capacity] = INT_MIN;
        capacity--;
        firstFree--;
    }
}

void ArrayList::print() const
{
    for (int i = 0; i < firstFree; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

ArrayList::~ArrayList()
{
    delete[] array;
}
