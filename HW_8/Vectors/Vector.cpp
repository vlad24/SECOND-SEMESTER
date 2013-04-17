#include "Vector.h"
#include <stdio.h>

Vector::Vector(int xCoord, int yCoord, int zCoord)
{
    abscissa = xCoord;
    ordinate = yCoord;
    applicate = zCoord;
}

Vector::Vector(const Vector& copiedObject)
{
    abscissa = copiedObject.abscissa;
    ordinate = copiedObject.ordinate;
    applicate = copiedObject.applicate;
}

bool Vector::isZero()
{
    return ((abscissa == 0) && (ordinate == 0) && (applicate == 0));
}

void Vector::printVector()
{
    printf("{%d ; %d ; %d}\n", abscissa, ordinate, applicate);
}

Vector *Vector::sumWithAnotherVector(Vector *another)
{
    int resAbscissa = this->abscissa + another->abscissa;
    int resOrdinate = this->ordinate + another->ordinate;
    int resApplicate = this->applicate + another->applicate;
    Vector* resultVector = new Vector(resAbscissa, resOrdinate, resApplicate);
    return resultVector;
}

Vector *Vector::subtractAnotherVector(Vector *another)
{
    int resAbscissa = this->abscissa - another->abscissa;
    int resOrdinate = this->ordinate - another->ordinate;
    int resApplicate = this->applicate - another->applicate;
    Vector* resultVector = new Vector(resAbscissa, resOrdinate, resApplicate);
    return resultVector;
}

int Vector::scalarProductWithAnotherVector(Vector *another)
{
    return (this->abscissa * another->abscissa) +
           (this->ordinate * another->ordinate) +
           (this->applicate * another->applicate);
}
