#pragma once
/*!
  An abstract class, which hashes a string and contains information
  about the size of the array to which the string will be put
  */
class Hasher
{
public:
    virtual int hashFunction(char* str) = 0;
    Hasher(): arraySize(31) {}
protected:
    const int arraySize;
};
