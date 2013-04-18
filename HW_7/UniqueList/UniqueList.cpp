#include "UniqueList.h"
#include "AddingError.h"
#include "DeletingError.h"

void UniqueList::add(int value)
{
    if (head != NULL)
    {
        ListElement* tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->value == value)
                throw AddingError();
            tmp = tmp->next;
        }
        if (tmp->value == value)
            throw AddingError();
        tmp->next = new ListElement;
        tmp->next->value = value;
        tmp->next->next = NULL;
    }
    else
    {
     head = new ListElement;
     head->next = NULL;
     head->value = value;
    }
}

void UniqueList::remove(int value)
{
    if (!(listIsEmpty()))
    {
       ListElement* tmp = head;
       ListElement* previous = tmp;
       while ((tmp->value != value))
       {
           previous = tmp;
           tmp = tmp->next;
           if (tmp == NULL)
               break;
       }
       if (tmp == NULL)
       {
            throw DeletingError();
       }
       else
       {
           if (tmp == head)
           {
               head = tmp->next;
               delete tmp;
           }
           else
           {
               previous->next = tmp->next;
               delete tmp;
           }
       }
    }
    else
    {
        printf("# Empty list.\n");
        throw DeletingError();
    }
}
