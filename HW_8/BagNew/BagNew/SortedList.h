#pragma once
#include <iostream>
using namespace std;

/*! A class that implements containing data (in a sorted way for better acces)
for faster counting number of addings to the set !*/
template <typename O>

class SortedList
{
    friend class ListTester;
public:
    SortedList() : head(NULL) {}
    void add(O value);
    void remove(O value);
    void printList() const;
    int repsOfElement(O value) const;
    ~SortedList();

private:

    struct ListElement
    {
        O value;
        int reps;
        ListElement* next;
    };
    ListElement* head;
    void insertElement(ListElement* &first, ListElement* &second, O value);
    /*! Returns a pointer to an element, also changing an additional pointer
        so that it points to previous element */
    ListElement* findElement(ListElement* &prev, O value) const
    {
        ListElement* suspected = head;
        if (!listIsEmpty())
        {
            while (suspected->value != value)
            {
                prev = suspected;
                suspected  = suspected->next;
                if (suspected == NULL)
                    break;
            }
            return suspected;
        }
        else
            return NULL;
    }
    bool listIsEmpty() const;
};

template <typename O>
bool SortedList<O>::listIsEmpty() const
{
    return (head == NULL) ;
}

template <typename O>
int SortedList<O>::repsOfElement(O value) const
{
    ListElement* prev = NULL;
    ListElement* tmp = findElement(prev, value);
    if (tmp != NULL)
        return tmp->reps;
    else
        return 0;
}

template <typename O>
SortedList<O>::~SortedList()
{
    if (!listIsEmpty())
    {
        ListElement* tmp  = head;
        ListElement* tmp2 = head;
        while (tmp != NULL)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
    }
}

template <typename O>
void SortedList<O>::insertElement(ListElement *&first, ListElement *&second, O value)
{
    first->next = new ListElement;
    first->next->value = value;
    first->next->reps = 1;
    first->next->next = second;
}

//template <typename O>
//SortedList<O>::ListElement* SortedList<O>::findElement(ListElement *&prev, O value) const
//{
//    ListElement* suspected = head;
//    if (!listIsEmpty())
//    {
//        while (supected->value != value)
//        {
//            prev = suspected;
//            suspected  = suspected->next;
//            if (suspected == NULL)
//                break;
//        }
//        return suspected;
//    }
//    else
//        return NULL;
//}

template <typename O>
void SortedList<O>::add(O value)
{
    if (!listIsEmpty())
    {
        ListElement* current = head;
        ListElement* previous = head;
        while (current->value < value)
        {
            previous = current;
            current = current->next;
            if (current == NULL)
                break;
        }
        if (current == previous)
        {
            if (current->value == value)
                current->reps++;
            else
            {
                head = new ListElement;
                head->value = value;
                head->next = current;
                head->reps = 1;
            }
        }
        else
        {
            if (current == NULL)
                insertElement(previous, current, value);
            else
            {
                if (current->value == value)
                    current->reps++;
                else
                    insertElement(previous, current, value);
            }
        }
    }
    else
    {
        head = new ListElement;
        head->value = value;
        head->next = NULL;
        head->reps = 1;
    }
}

template <typename O>
void SortedList<O>::remove(O value)
{
    if (!listIsEmpty())
    {
        ListElement* previous = NULL;
        ListElement* found = findElement(previous, value);
        if (previous == NULL)
        {
            if (head->reps == 1)
            {
                ListElement* tmp = head;
                head = head->next;
                delete tmp;
            }
            else
                head->reps--;
        }
        else
        {
            if (found != NULL)
            {
                if (found->reps == 1)
                {
                    ListElement* tmp = found;
                    previous->next = found->next;
                    delete tmp;
                }
                else
                    found->reps--;
            }
        }
    }
}

template <typename O>
void SortedList<O>::printList() const
{
    if (!listIsEmpty())
    {
        ListElement* tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->value << "(" <<  tmp->reps << ") ";
            tmp = tmp->next;
        }
    }
}
