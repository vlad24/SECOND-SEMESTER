#pragma once

class PointerList
{
    friend class ListTester;
public:
    PointerList();
    void add(int value);
    void remove(int value);
    bool exsists(int value) const;
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
