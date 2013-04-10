#pragma once
#include "Hasher.h"
/*!
    A class that hashes a string by writing all codes of symbols to a string
    in binary representation and then interpreting that string as a number written in base 3
  */
class BaseHasher : public Hasher
{
public:
    int hashFunction(char *str);
private:
    //! \param bin a string of all binary codes of all symbols
    int countInThreeBase(char* bin);
};
