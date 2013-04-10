#pragma once
#include <stdio.h>

//! A class object of which is thrown after an attempt to add an exsisting element
class AddingError
{
public:
    AddingError()
    {
        printf("# ADDING ERROR!\n");
    }
};
