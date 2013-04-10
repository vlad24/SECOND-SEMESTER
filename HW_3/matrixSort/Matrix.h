#pragma once

class Matrix
{
    friend class MatrixSortTester;

public:
    /*!
      @param M a wifth of a atrix that will be created
      @param N a hight of a matrix that will be created
      */
    Matrix(int M, int N);
    void printMatrix();
    void fillMatrix();
    void fillMatrixRandomly();
    /*!
      @brief A function that will sort columns of the matrix using the private method swapColumns()
      @see swapColumns()
      */
    void sortColumns();
    ~Matrix();
private:
    int** table;
    int width;
    int height;
    /*!
      @brief A function that swap columns by swaping the pointers to them.
      @details Columns are compared by firstColumnIsMore()
      @param pointer1 the pointer1 to the first column of the matrix
      @param pointer1 the pointer to the second column of the matrix
      @see firstColumnIsMore()
      */
    void swapColumns(int *&pointer1, int *&pointer2);
    /*!
      @brief A function that compare two columns of the matrix by comparing the top elements
      */
    bool firstColumnIsMore(int* &column1, int* &column2);
};

