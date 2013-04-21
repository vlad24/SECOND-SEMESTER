#pragma once
#include <iostream>
#include "DimError.h"
using namespace std;

template <typename O>
class Vector
{
    friend class VectorTester;
public:
    //! A constructor which creates a vector, array of coordinates
    Vector(O *coordinatesArray, int length);
    //! Copying constructor
    Vector(const Vector& copiedObject);
    bool isZero(O zeroSign);
    void printVector();
    //! Overloaaded operators for summing, subtracting and scalar product
    Vector operator+(Vector another);
    Vector operator-(Vector another);
    O operator*(Vector another);
protected:
    int N;
    O* coordinates;
};

template <typename O>
Vector<O>::Vector(O *coordinatesArray, int length)
{
    coordinates = new O[length];
    N = length;
    for (int i = 0; i < length; i++)
        coordinates[i] = coordinatesArray[i];
}

template <typename O>
Vector<O>::Vector(const Vector &copiedObject)
{
    N = copiedObject.N;
    coordinates = new O[N];
    for (int i = 0; i < N; i++)
        coordinates[i] = copiedObject.coordinates[i];
}

template <typename O>
bool Vector<O>::isZero(O zeroSign)
{
    bool isReallyZero = true;
    int i = 0;
    while (isReallyZero && (i < N))
    {
        isReallyZero = (coordinates[i] == zeroSign);
        i++;
    }
    return isReallyZero;
}

template <typename O>
void Vector<O>::printVector()
{
    cout << "{";
    for (int i = 0; i < N; i++)
    {
        cout << coordinates[i];
        if (i != N - 1)
            cout << ";";
    }
    cout << "}" << endl;
}

template <typename O>
Vector<O> Vector<O>::operator+(Vector another)
{
        if (N == another.N)
        {
            int* newCoordinates = new O[N];
            for (int i = 0; i < N; i++)
                newCoordinates[i] = coordinates[i] + another.coordinates[i];
            Vector resultVector = Vector(newCoordinates, N);
            return resultVector;
        }
        else
            throw DimError();
}

template <typename O>
Vector<O> Vector<O>::operator-(Vector another)
{
        if (N == another.N)
        {
            O* newCoordinates = new O[N];
            for (int i = 0; i < N; i++)
                newCoordinates[i] = coordinates[i] - another.coordinates[i];
            Vector resultVector = Vector(newCoordinates, N);
            return resultVector;
        }
        else
            throw DimError();
}

template <typename O>
O Vector<O>::operator*(Vector another)
{
    if (N == (another.N))
    {
        int product = 0;
        for (int i = 0; i < N; i++)
        {
            product += coordinates[i] * another.coordinates[i];
        }
        return product;
    }
    else
        throw DimError();

}
