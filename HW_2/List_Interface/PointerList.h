#pragma once
#include "ListInterface.h"

class PointerList : public ListInterface
{
    friend class ListTester;
public:
    PointerList();
    void add(int value);
    void remove(int value);
    void print() const;
    ~PointerList();
private:
    struct ListElement
    {
        int value;
        ListElement* next;
    };
    ListElement* head;
    bool listIsEmpty() const;
};
