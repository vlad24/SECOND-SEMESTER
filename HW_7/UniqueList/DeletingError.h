#pragma once
#include <stdio.h>

class DeletingError
{
public:
    DeletingError()
    {
        printf("# DELETING ERROR!\n");
    }
};
