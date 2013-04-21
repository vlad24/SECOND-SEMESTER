#pragma once
#include <iostream>
using namespace std;
//! A class for an exception when two vectros of different dimensions are summed, subtracted, multiplied
class DimError
{
public:
    DimError()
    {
        cout << "#Dimensions of vectors are not equal.\n";
    }
};
