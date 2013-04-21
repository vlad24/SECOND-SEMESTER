#include <iostream>
#include "VectorTester.h"
#include "Vector.h"

using namespace std;

int main()
{
    VectorTester tester;
    QTest::qExec(&tester);
    cout<<"---------\n";
    int c1[3] = {2,2,2};
    int c2[3] = {7,7,7};
    Vector<int> v1 = Vector<int>(c1, 3);
    Vector<int> v2 = Vector<int>(c2, 3);
    Vector<int> v3 = Vector<int>(v2);
    v3 = v1 - v2;
    v1.printVector();
    v2.printVector();
    v3.printVector();
    int product = v1 * v3;
    cout << product << " ";
}

