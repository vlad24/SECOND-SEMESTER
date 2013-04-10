#pragma once
#include "ListInterface.h"

class ArrayList : public ListInterface
{
    friend class ListTester;
public:
    ArrayList();
    void add(int j);
    void remove(int value);
    void print() const;
    ~ArrayList();
private:
    int* array;
    int firstFree;
    int capacity;
};
