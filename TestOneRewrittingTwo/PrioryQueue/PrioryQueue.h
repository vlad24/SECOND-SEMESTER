#pragma once
#include <iostream>
#include "EmptyQueueError.h"
using namespace std;

template <typename W>
//! Class which implements a simple queue with priorities with operations of adding, taking and printing the queue
class PrioryQueue
{
    friend class QueueTester;
public:
    PrioryQueue(): head(NULL) {}
    /*! A function, which adds an element to the queue, maintaining sorted order of priorities */
    void enqueue(W value, int priority);
    /*! A function, which returns the element of the queue with
    the highest priority!*/
    W dequeue();
    void printQueue() const;
    ~PrioryQueue();

private:
    struct QueueElement
    {
        W value;
        int priority;
        QueueElement* next;
    };

    QueueElement* head;
    bool isEmpty() const;
    //! A function, which fills fields of the given element after creation
    void initializeElement(QueueElement* &element, W value, int priority, QueueElement *next);
};

template <typename W>
void PrioryQueue<W>::initializeElement(PrioryQueue::QueueElement *&element,
                                    W value, int priority, QueueElement *next)
{
    element->value = value;
    element->priority = priority;
    element->next = next;
}

template <typename W>
void PrioryQueue<W>::enqueue(W value, int priority)
{
    if (!isEmpty())
    {
        QueueElement* current = head;
        QueueElement* previous = head;
        while (current->priority > priority)
        {
            previous = current;
            current = current->next;
            if (current == NULL)
                break;
        }
        if (current == previous) // at the beginning
        {
            head = new QueueElement();
            initializeElement(head, value, priority, current);
        }
        else // somewhere to the middle or end
        {
            previous->next = new QueueElement();
            initializeElement(previous->next, value, priority, current);
        }

    }
    else // the first element is appearing
    {
        head = new QueueElement();
        initializeElement(head, value, priority, NULL);
    }
}

template <typename W>
W PrioryQueue<W>::dequeue()
{
    if (!isEmpty())
    {
        W result = head->value;
        QueueElement* tmp = head;
        head = head->next;
        delete tmp;
        return result;
    }
    else
        throw EmptyQueueError();
}

template <typename W>
bool PrioryQueue<W>::isEmpty() const
{
    return (head == NULL);
}

template <typename W>
void PrioryQueue<W>::printQueue() const
{
    if (!isEmpty())
    {
        QueueElement* current = head;
        do
        {
            cout << current->value << " ";
            current = current->next;
        }
        while (current != NULL);
    }
    cout << endl;
}

template <typename W>
PrioryQueue<W>::~PrioryQueue()
{
    if (!isEmpty())
    {
        QueueElement* current = head;
        QueueElement* prev = head;
        while (current != NULL)
        {
            prev = current;
            current = current->next;
            delete prev;
        }
    }
}
