#pragma once

template <typename W>

/*! A template class which can compare two elements saying whether
  the first given element is "more" than second*/

class Comparator
{
public:
    virtual bool firstIsMore(W first, W second) = 0;
};
