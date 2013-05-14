#pragma once
#include "stdio.h"

//! This exception is thrown when a user tryes to take an element from an empty queue

class EmptyQueueError
{
public:
    EmptyQueueError()
    {
        printf("EMPTY QUEUE ERROR!\n");
    }
};
