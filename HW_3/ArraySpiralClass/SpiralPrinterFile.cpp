#include "SpiralPrinterFile.h"

SpiralPrinterFile::SpiralPrinterFile(FILE* userFile, int sideLength)
{
    file = userFile;
    side = sideLength;
    spiralString = new int[side * side];
}

void SpiralPrinterFile::spiralPrint(int** array)
{
    goSpiral(array);
    for (int i = 0; i < side * side; i++)
    {
        fprintf(file, "%d ", spiralString[i]);
    }
}
