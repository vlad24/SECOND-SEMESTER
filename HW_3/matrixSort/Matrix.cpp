#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix::Matrix(int M, int N)
{
    table = new int*[N];
    for (int n = 0; n < N; n++)
    {
        table[n] = new int[M];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            table[i][j] = 0;
    height = M;
    width = N;
}

void Matrix::printMatrix()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            printf("%d ", table[x][y]);
            if (x == width - 1)
                printf("\n");
        }
}

void Matrix::fillMatrix()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            scanf("%d", &(table[x][y]));
}

void Matrix::fillMatrixRandomly()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            table[x][y] = rand() % 10;
}

bool Matrix::firstColumnIsMore(int* &column1, int* &column2)
{
    return ((column1[0]) > (column2[0]));
}

void Matrix::swapColumns(int* &pointer1, int* &pointer2)
{
    int* tmp = NULL;

    tmp = pointer1;
    pointer1 = pointer2;
    pointer2 = tmp;
}

void Matrix::sortColumns() //actually it is an insertSorting of pointers
{
    int k = 0;
    for (int x = 1; x < width; x++)
    {
        k = x;
        while (firstColumnIsMore(table[k - 1], table[k]))
        {
           swapColumns(table[k], table[k - 1]);
           k--;
           if (k == 0)
               break;
        }
    }
}

Matrix::~Matrix()
{
    for (int u = 0; u < width; u++)
    {
        delete[] table[u];
    }
    delete[] table;
}
