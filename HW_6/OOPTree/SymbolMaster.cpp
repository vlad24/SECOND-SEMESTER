#include "SymbolMaster.h"

bool SymbolMaster::isSign(char c) const
{
    return((c == '*') || (c == '-') || (c == '/') || (c == '+'));
}

bool SymbolMaster::isGap(char c) const
{
    return (c == ' ');
}

bool SymbolMaster::isBracket(char c) const
{
    return ((c == '(') || (c == ')'));
}
