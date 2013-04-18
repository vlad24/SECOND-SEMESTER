#pragma once

class PointerList
{
    friend class ListTester;
public:
    PointerList();
    virtual void add(int value);
    virtual void remove(int value);
    void print() const;
    ~PointerList();
protected:
    struct ListElement
    {
        int value;
        ListElement* next;
    };
    ListElement* head;
    bool listIsEmpty() const;
};
