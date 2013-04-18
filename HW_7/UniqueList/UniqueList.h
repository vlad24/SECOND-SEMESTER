#pragma once
#include "PointerList.h"

class UniqueList : public PointerList
{
public:
    void add(int value);
    void remove(int value);
};
