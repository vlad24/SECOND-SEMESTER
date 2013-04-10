#pragma once

class ListInterface
{
//friend class ListTester;
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() const = 0;
    virtual ~ListInterface()
    {

    }
};
