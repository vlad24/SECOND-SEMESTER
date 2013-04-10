#include "BaseHasher.h"
#include <string.h>
#include <stdio.h>
#include <QDebug>

int BaseHasher::countInThreeBase(char *bin)
{
    int i = 0;
    int threePow = 1;
    int threeSum = 0;
    while (bin[i] != '\0')
    {
        int binDigit = int(bin[i]) - int('0');
        threeSum = (threeSum + (binDigit * threePow)) % arraySize;
        threePow = (threePow * 3) % arraySize;
        i++;
    }
    return threeSum;
}

int BaseHasher::hashFunction(char *str)
{
    int stringPos = 0;
    int binPos = 0;
    char reversedBin[1000] = "";
    while ((str[stringPos] != '\0') && (str[stringPos] != '\n'))
    {
        int code = int(str[stringPos]);
        while (code != 0)
        {
            int codeMask = code;
            int evenMask = (codeMask >> 1) << 1;
            if (codeMask ^ evenMask)
            {
                reversedBin[binPos] = '1';
                binPos++;
            }
            else
            {
                reversedBin[binPos] = '0';
                binPos++;
            }
            code = code >> 1;
        }
        stringPos++;
    }
    int threeHash = countInThreeBase(reversedBin) % arraySize;
    return threeHash;
}
