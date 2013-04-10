#pragma once
#include "Hasher.h"
/*!
  A class that hashes a string by simply summing symbols codes
  with a sign depending on a position of a symbol in a string
  */
class CommonHasher : public Hasher
{
public:
    int hashFunction(char* str);
};
