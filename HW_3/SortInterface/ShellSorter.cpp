#include <stdio.h>
#include "ShellSorter.h"

const int ShellSorter::primeSteps[6] = {13,11,7,5,3,1};

int ShellSorter::largestPossiblePrimeStep(int length) const
{
    int stepIndex = 0;
    for (stepIndex = 0; stepIndex < 6; stepIndex++)
    {
        if (length >= primeSteps[stepIndex])
            break;
    }
    return stepIndex;
}

void ShellSorter::sortArray(int array[], int length)
{
    int last = length - 1;
    int startStepIndex = largestPossiblePrimeStep(length);
    for (int stepIndex = startStepIndex; stepIndex < 6; stepIndex++)
    {
        int currentStep = primeSteps[stepIndex];
        // going through all currentStep-subsequences taking as a start all mods V
        int mod = 0;
        while(mod < currentStep)
        {
            // going over the subsequence V
            int jumpIndex = mod + currentStep;
            while (jumpIndex <= last)
            {
                int i = jumpIndex;
                while (array[i] < array[i - currentStep]) // Insert-sorting subsequence
                {
                    int buffer = array[i];
                    array[i] = array[i - currentStep];
                    array[i - currentStep] = buffer;
                    i -= currentStep;
                    if (i < currentStep)
                        break;
                }
                jumpIndex += currentStep;
            }
            mod++;
        }
    }
}
