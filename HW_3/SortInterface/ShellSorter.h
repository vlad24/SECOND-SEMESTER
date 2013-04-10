#pragma once
#include "SortInterface.h"

class ShellSorter : public SortInterface
{
public:
    void sortArray(int array[], int length);
private:
    //! Steps using wchich each insert sort iteration will bw made
    static const int primeSteps[6];
    //! Function, which makes the first step safe enough no to go beyond the end of the array
    int largestPossiblePrimeStep(int length) const;
};
