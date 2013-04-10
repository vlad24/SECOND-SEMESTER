#pragma once
#include "StackInterface.h"

class PointerStack : public StackInterface
{
    friend class StackTester;
public:
    PointerStack();
    void push(int value);
    int pop();
    int top() const;
    void printStack() const;
    void clear();
    ~PointerStack();
private:
    struct StackElement
    {
        int value ;
        StackElement* next ;
    };
    StackElement* head;
    bool isEmpty() const;
};
