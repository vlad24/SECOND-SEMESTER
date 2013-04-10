#pragma once
#include "Hasher.h"
/*!
    A class that hashes a string by summing codes of symbols multiplied on
    a prime number in the degree depending on a position of a symbol in a string
  */
class PolynomialHasher : public Hasher
{
public:
    int hashFunction(char* str);
};
