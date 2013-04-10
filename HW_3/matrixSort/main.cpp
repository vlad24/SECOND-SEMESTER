#include <stdio.h>
#include "Matrix.h"
#include "MatrixSortTester.h"

int main()
{
    MatrixSortTester tester;
    QTest::qExec(&tester);
    printf("A matrix M x N will be created and sorted afterwards\n");

    printf("Enter M:\n");
    int M = 0;
    scanf("%d", &M);

    printf("Enter N:\n");
    int N = 0;
    scanf("%d", &N);

    Matrix* matrix = new Matrix(M, N);
    printf("Fill your matrix:\n");
    matrix->fillMatrix();
    matrix->sortColumns();
    printf("------\n");
    matrix->printMatrix();
    delete matrix;
    return 0;
}

