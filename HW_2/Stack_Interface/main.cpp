#include <stdio.h>
#include "PointerStack.h"
#include "ArrayStack.h"
#include "StringCalculator.h"
#include "StackTester.h"

int main()
{
    StackTester tester;
    QTest::qExec(&tester);
    int answer = 0;
    printf("Hello. With what type of Stack you would like to work?\n");
    printf("0 - pointer stack ; 1 - array stack\n");
    scanf("%d", &answer);
    StackInterface* stackObject;
    if (answer)
    {
        stackObject = new ArrayStack();
    }
    else
    {
        stackObject = new PointerStack();
    }

    printf ("Stack has been successfully created.\n");
    printf("0 - exit and destroy stack;\n1 - push to stack;\n2 - pop from stack;\n3 - print stack\n4 - clear stack\n5 - calculate an expression\n");
    bool stopIt = false;
    while (!stopIt)
    {
        printf("\nWhat now?:");
        scanf("%d", &answer);
        switch (answer)
        {
        case 0:
        {
            delete stackObject;
            stopIt = true;
            break;
        }
        case 1:
        {
            int value = 0;
            printf("What value?\n");
            scanf("%d", &value);
            stackObject->push(value);
            break;
        }
        case 2:
        {
            int value = stackObject->pop();
            printf("%d", value);
            break;
        }
        case 3:
        {
            stackObject->printStack();
            break;
        }
        case 4:
        {
            stackObject->clear();
            break;
        }
        case 5:
        {
            printf("Enter your expression:\n");
            char string[576] = {};
            scanf("%s", string);
            StringCalculator* calculator = new StringCalculator();
            int result = calculator->calculateExpression(string);
            printf("%d", result);
            delete calculator;
            break;
        }
        default:
        {
            stopIt = true;
            break;
        }
        }
    }
    return 0;
}
