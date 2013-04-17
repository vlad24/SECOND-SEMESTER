#include <iostream>
#include "Vector.h"
#include "VectorTester.h"

using namespace std;

int main()
{
    VectorTester tester;
    QTest::qExec(&tester);
    Vector v1(9, 9, 9);
    Vector v2(0, 0, 0);
    Vector v3(v2);
    v1.printVector();
    v2.printVector();
    v3.printVector();
}

