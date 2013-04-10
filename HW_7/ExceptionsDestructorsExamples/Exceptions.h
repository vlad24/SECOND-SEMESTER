#pragma once
#include <stdio.h>

class SomeClass
{
public:
    SomeClass()
    {
        printf("Constructor of SomeCLass is called\n");
    }
    ~SomeClass()
    {
        printf("Destructor of Some class is called\n");
    }
};

class Error
{
public:
    Error() : exceptionValue('E')
    {
        throw exceptionValue;
    }
protected:
    char exceptionValue;
    SomeClass testClass;

};
