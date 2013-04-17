#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector v1(9, 9, 9);
    Vector v2 = v1;
    v1.printVector();
    v2.printVector();
}

