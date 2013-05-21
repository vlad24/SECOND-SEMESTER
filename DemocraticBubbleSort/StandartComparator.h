#pragma once
#include "Comparator.h"

template <typename W>

/*! A template class which compares two elements arithmetically*/

class StandartComparator : public Comparator<W>
{
public:
    bool firstIsMore(W first, W second)
    {
        return (first > second);
    }
};
