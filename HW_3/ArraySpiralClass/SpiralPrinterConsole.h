#pragma once
#include "SpiralMaker.h"

class SpiralPrinterConsole : public SpiralMaker
{
public:
    SpiralPrinterConsole(int sideLength);
    void spiralPrint(int** array);
};
