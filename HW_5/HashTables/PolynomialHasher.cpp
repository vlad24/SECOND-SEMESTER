#include "PolynomialHasher.h"

int PolynomialHasher::hashFunction(char *str)
{
    int p = 5;
    int pPower = 1;
    int j = 0;
    int sum = 0;
    while((str[j] != '\0') && (str[j] != '\n'))
    {
        int letterOrd = int(str[j]) % arraySize;
        int adder = ((letterOrd) * (pPower)) % arraySize;
        sum = (sum + adder) % arraySize;
        pPower = (pPower * p) % arraySize;
        j++;
    }
    while (sum < 0)
    {
        sum += arraySize;
    }
    return sum ;
}
