#include "PrioryQueue.h"
#include "QueueTester.h"
#include <iostream>

using namespace std;

int main()
{
    QueueTester tester;
    QTest::qExec(&tester);
    return 0;
}

