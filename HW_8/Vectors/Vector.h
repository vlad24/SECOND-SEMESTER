#pragma once

class Vector
{
public:
    Vector(int xCoord, int yCoord, int zCoord);
    Vector(const Vector& copiedObject);
    bool isZero();
    void printVector();
    Vector* sumWithAnotherVector(Vector* another);
    Vector* subtractAnotherVector(Vector* another);
    int scalarProductWithAnotherVector(Vector* another);
private:
    int abscissa;
    int ordinate;
    int applicate;
};
