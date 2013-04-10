#include "ArrayStack.h"
#include <limits.h>
#include <stdio.h>

const int size = 576;

ArrayStack::ArrayStack()
{
    array = new int[size];
    capacity = size - 1;
    firstFree = 0;
    for (int i = 0; i <= capacity; i++)
    {
        array[i] = INT_MIN;
    }
}

int ArrayStack::top() const
{
    if (firstFree == 0)
        return INT_MIN;
    else
        return array[firstFree - 1];
}

void ArrayStack:: push(int j)
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

       array = array2;
       firstFree = capacity + 2;
       capacity = doubleCapacity - 1;
    }
}

int ArrayStack::pop()
{
    if (firstFree != 0)
    {
        int result = array[firstFree - 1];
        firstFree--;
        array[firstFree] = INT_MIN;
        return result;
    }
}

void ArrayStack::printStack() const
{
    if (firstFree != 0)
    {
        for (int i = firstFree - 1; i >= 0; i--)
        {
            printf("%d ", array[i]);
        }
    }
    else
    {
        printf("You have an empty stack.");
    }
    printf("\n");
}

void ArrayStack::clear()
{
    for (int i = 0; i < firstFree; i++)
    {
        array[i] = INT_MIN;
    }
    firstFree = 0;
}

ArrayStack::~ArrayStack()
{
    delete[] array;
    firstFree = 0;
}
