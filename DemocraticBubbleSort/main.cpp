#include <iostream>
#include "BubbleSorter.h"
#include "BubbleSorterTester.h"
#include "StandartComparator.h"
#include "QuadroComparator.h"

using namespace std;

int main()
{
    BubbleSorterTester sorterTester;
    QTest::qExec(&sorterTester);
}

