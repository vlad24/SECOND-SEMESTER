#include "CommonHasher.h"

int CommonHasher::hashFunction(char* str)
{
    int i = 0;
    int codeSum = 0;
    while ((str[i] != '\0') && (str[i] != '\n'))
    {
        if (i % 2 == 0)
            codeSum = (codeSum + int(str[i])) % arraySize;
        else
            codeSum = (codeSum - int(str[i])) % arraySize;
        i++;
    }
    while (codeSum < 0)
    {
        codeSum += arraySize;
    }
    return codeSum % arraySize;

}
