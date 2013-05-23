#pragma once
#include <stdio.h>

//! Error which is thrown if an iterator does not have an element to return
class TakingError
{
public:
    TakingError()
    {
        printf("#ERROR!\n");
    }
};
