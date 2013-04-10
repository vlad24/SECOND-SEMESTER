#include "SpiralMaker.h"

void SpiralMaker::goSpiral(int** array)
{
    int edge = side - 1;
    int downBorder = edge / 2 + 1;
    int leftBorder = edge / 2 - 1;
    int upBorder = edge / 2 - 1;
    int rightBorder = edge / 2 + 1;

    int i = edge / 2;
    int j = edge / 2;
    int u = 0;

    while (!((i == 0) && (j == edge)))
    {
        // moving down
        do
        {
            // spiralString[u++] array[i][j]);
            spiralString[u++] = array[i][j];
            i++;
        }
        while (i < downBorder);

        downBorder++;

        // moving left
        do
        {
            spiralString[u++] = array[i][j];
            j--;
        }
        while(j > leftBorder);

        leftBorder--;

        // moving up
        do
        {
            spiralString[u++] = array[i][j];
            i--;
        }
        while (i > upBorder) ;

        upBorder--;

        // moving right
        do
        {
            spiralString[u++] = array[i][j];
            j++;
        }
        while(j < rightBorder);

        rightBorder++;

    }

    // do not forget about the last column
    for(i = 0 ; i <= edge ; i++)
        spiralString[u++] = array[i][j];
}

SpiralMaker::~SpiralMaker()
{
    delete[] spiralString;
}
