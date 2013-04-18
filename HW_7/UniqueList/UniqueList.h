#pragma once
#include "PointerList.h"
//! A class where you can add an element once and remove only exsisting elements
class UniqueList : public PointerList
{
public:
    void add(int value);
    void remove(int value);
};
