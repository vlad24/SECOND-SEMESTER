#pragma once
#include <stdio.h>
#include "SpiralMaker.h"

class SpiralPrinterFile : public SpiralMaker
{
public:
    FILE* file;
    SpiralPrinterFile(FILE* file, int sideLength);
    void spiralPrint(int** array);
};
