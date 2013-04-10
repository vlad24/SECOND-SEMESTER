#include <stdio.h>
#include "ArrayList.h"
#include "PointerList.h"
#include "ListTester.h"

int main()
{
    ListTester tester;
    QTest::qExec(&tester);
    int answer = 0;
    printf("Hello. With what type of List you would like to work?\n");
    printf("0 - pointer list ; 1 - array list\n");
    scanf("%d", &answer);
    ListInterface* listObject;
    if (answer)
    {
        listObject = new ArrayList();
    }
    else
    {
       listObject = new PointerList();
    }

    printf ("List has been successfully created.\n");
    printf("0 - exit and destroy list;\n1 - add to list;\n2 - rm from list;\n3 - print list\n");
    bool stopIt = false;
    while (!stopIt)
    {
        printf("\nWhat now?:");
        scanf("%d", &answer);

        switch(answer)
        {
            case 0:
            {
                delete listObject;
                stopIt = true;
                break;
            }
            case 1:
            {
                int value = 0;
                printf("What value?\n");
                scanf("%d", &value);
                listObject->add(value);
                break;
            }
            case 2:
            {
                int value = 0;
                printf("What value?\n");
                scanf("%d", &value);
                listObject->remove(value);
                break;
            }
            case 3:
            {
                listObject->print();
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
