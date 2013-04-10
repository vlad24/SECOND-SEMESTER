#include <stdio.h>
#include <string.h>
#include "List.h"

List::List()
{
    listLength = 0;
    first = NULL;
}

bool List::isEmpty() const
{
    return (first == NULL);
}


int List::getLength() const
{
    return listLength;
}

void List::print() const
{
    if (!isEmpty())
    {
        ListElement* tmp = first;
        for (int j = 1; j <= listLength; j++)
        {
            printf("%s", tmp->value) ;
            tmp = tmp->next ;
        }
        printf("\n");
    }
}

bool List::stringsEqual(char* s1, char *s2) const
{
    int j = 0;
    bool equal = true;
    if ((s1 != NULL) && (s2 != NULL))
    {
        while((s1[j] != '\0') && (s2[j]!='\0') && equal)
        {
            if (!(s1[j] == s2[j]))
            {
                equal = false;
                break;
            }
            j++;
        }
    }
    else
    {
        printf("Error : NULL strings were tried to be compared\n");
        equal = false;
    }
    return equal;
}

List::ListElement* List::searchString(char *str, List::ListElement *&prev) const

{
    ListElement* current = first;
    ListElement* previous = first;
    if (!isEmpty())
    {
        int i = 1;
        while (i <= listLength)
        {
            if (!stringsEqual(current->value, str))
            {
                previous = current;
                current = current->next;
                i++;
            }
            else
                break;
        }
    }
    prev = previous;
    return current;
}


//ADD and REMOVE realisation:
void List::add(char* str)
{
    if (!isEmpty())
    {
        ListElement* prev = NULL;
        ListElement* similar = searchString(str, prev);
        if (similar == NULL)
        {
            prev->next = new ListElement;
            prev->next->next = NULL;
            prev->next->value = strdup(str);
            listLength++;
        }
    }
    else
    {
        first = new ListElement;
        first->value = strdup(str);
        first->next = NULL;
        listLength++;
    }
}

void List::remove(char* str)
{
    if (!isEmpty())
    {
        ListElement* prev = NULL;
        ListElement* foundString = searchString(str, prev);
        if (foundString != NULL)
        {
            if (foundString == first)
            {
                first = first->next;
                delete foundString;
            }
            else
            {
                prev->next = foundString->next;
                delete foundString;
            }
            listLength--;
        }
    }
}
//
List::ListElement *List::takeElement(int pos) const
{
    if (!isEmpty())
    {
        if (pos <= getLength())
        {
            int i = 1;
            ListElement* result = first;
            while (i < pos)
            {
                result = result->next;
                i++;
            }
            return result;
        }
        else
            return NULL;
    }
    else
        return NULL;
}

bool List::stringExsists(char* str) const
{
    ListElement* tmp;
    ListElement* exsistingOne = searchString(str, tmp);
    return (exsistingOne != NULL);
}

List::~List()
{
    if (!isEmpty())
	{
        ListElement* current = first;
        while (current != NULL)
		{
            ListElement* prev = current;
            current = current->next;
            delete prev->value;
            delete prev;
        }
    }
}
