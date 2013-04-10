#pragma once

//! A class which can work out whether the symbol is a sign of arithmetic operation or not

class SymbolMaster
{
public:
    bool isSign(char c) const;
    bool isGap(char c) const;
    bool isBracket(char c) const;
};

