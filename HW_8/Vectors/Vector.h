#pragma once

class Vector
{
    friend class VectorTester;
public:
    //! A constructor which creates a vector, using three coordinates
    Vector(int xCoord, int yCoord, int zCoord);
    //! Copying constructor
    Vector(const Vector& copiedObject);
    bool isZero();
    void printVector();
    Vector* sumWithAnotherVector(Vector* another);
    Vector* subtractAnotherVector(Vector* another);
    int scalarProductWithAnotherVector(Vector* another);
protected:
    int abscissa;
    int ordinate;
    int applicate;
};
