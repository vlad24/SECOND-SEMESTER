#pragma once

class SpiralMaker
{
public:
    virtual void spiralPrint(int** array) = 0;
    ~SpiralMaker();
protected:
    int side;
    int* spiralString;

    void goSpiral(int** array);
};
