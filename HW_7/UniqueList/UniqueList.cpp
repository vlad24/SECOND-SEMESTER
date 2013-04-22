#include "UniqueList.h"
#include "AddingError.h"
#include "DeletingError.h"

void UniqueList::addCarefully(int value)
{
    if (!exsists(value))
        add(value);
    else
        throw AddingError();
}

void UniqueList::removeCarefully(int value)
{
    if (exsists(value))
        remove(value);
    else
        throw DeletingError();
}
