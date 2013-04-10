#pragma once

class StackInterface
{
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual int top() const = 0;
    virtual void printStack() const = 0;
    virtual void clear() = 0;
    virtual ~StackInterface()
    {

    }
};
