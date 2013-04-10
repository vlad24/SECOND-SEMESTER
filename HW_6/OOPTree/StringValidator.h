#pragma once
#include "SymbolMaster.h"

//! A class which checks the sequence of symbols in a prefix string

class StringValidator : public SymbolMaster
{
public:
    bool basicValidation(char* s) const;
    char *avoidBracketsAndGaps(char* str);
};

