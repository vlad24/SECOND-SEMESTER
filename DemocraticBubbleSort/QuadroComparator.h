#pragma once
#include "Comparator.h"

template <typename W>

/*! A template class which compares two elements by arithmetical
comparison of their squares*/

class QuadroComparator : public Comparator<W>
{
public:
    bool firstIsMore(W first, W second)
    {
        return (first * first) > (second * second);
    }
};
