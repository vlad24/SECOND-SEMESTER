#pragma once
#include "StackInterface.h"

class ArrayStack : public StackInterface
{
    friend class StackTester;
public:
    ArrayStack();
    void push(int j);
    int pop();
    int top() const;
    void printStack() const;
    void clear();
    ~ArrayStack();
private:
    int* array;
    int capacity;
    int firstFree;
};
