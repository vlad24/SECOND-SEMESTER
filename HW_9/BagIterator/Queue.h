#pragma once
#include "TakingError.h"
template <typename O>

class Queue
{
public:
    struct QueueElement
    {
        O value;
        QueueElement* next;
    };

    Queue() : head(NULL), tail(NULL) {}

    void add(O value);

    O take();

    bool isEmpty()
    {
        return (head == NULL);
    }

    ~Queue();

private:
    QueueElement* head;
    QueueElement* tail;
};

template <typename O>
void Queue<O>::add(O value)
{
    if (!isEmpty())
    {
        tail->next = new QueueElement;
        tail->next->value = value;
        tail->next->next = NULL;
        tail = tail->next;
    }
    else
    {
        tail = new QueueElement();
        tail->value = value;
        tail->next = NULL;
        head = tail;
    }
}

template <typename O>
O Queue<O>::take()
{
    if (!isEmpty())
    {
        O result = head->value;
        QueueElement* tmp = head;
        head = head->next;
        delete tmp;
        if (head == NULL)
            tail = NULL;
        return result;
    }
    else
        throw TakingError();
}

template <typename O>
Queue<O>::~Queue()
{
    while(!isEmpty())
        take();
}
