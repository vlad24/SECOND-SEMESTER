#include <stdio.h>
#include "SpiralPrinterConsole.h"

SpiralPrinterConsole::SpiralPrinterConsole(int sideLength)
{
    side = sideLength;
    spiralString = new int[side * side];
}

void SpiralPrinterConsole::spiralPrint(int **array)
{
    goSpiral(array);
    for (int i = 0; i < side * side; i++)
    {
        printf("%d ", spiralString[i]);
    }
}
