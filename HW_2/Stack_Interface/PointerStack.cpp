#include "PointerStack.h"
#include <limits.h>
#include <stdio.h>

PointerStack::PointerStack()
{
    head = NULL;
}

bool PointerStack::isEmpty() const
{
    return (head == NULL);
}

int PointerStack::top() const
{
    if (!isEmpty())
    {
        return head->value;
    }
    else
    {
        return INT_MIN;
    }
}

void PointerStack::push(int value)
{
    if (!isEmpty())
    {
            StackElement* temp = new StackElement;
            temp->value = value;
            temp->next = head;
            head = temp;
    }
    else
    {
        head = new StackElement;
        head->next = NULL;
        head->value = value;
    }
}

int PointerStack::pop()
{
    if (!isEmpty())
    {
        int result = head->value;
        StackElement* tmp = head;
        head = head->next;
        delete tmp;
        return result;
    }
}

void PointerStack::printStack() const
{
   if (!isEmpty())
   {
       StackElement* temp = head;

        while (temp != NULL)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }
   }
   else
   {
       printf("You have an empty stack.");
   }
   printf("\n");
}

void PointerStack::clear()
{
    StackElement* tmp = head ;
    if (!isEmpty())
    {
        while (tmp->next != NULL)
        {
            StackElement* tmp2 = tmp ;
            tmp = tmp->next ;
            delete tmp2;
        }
        delete tmp ;
        head = NULL;
    }
}

PointerStack::~PointerStack()
{
    clear();
}
