#include <stdio.h>
#include "Tester.h"
#include "UniqueList.h"
#include "DeletingError.h"
#include "AddingError.h"

int main()
{
    Tester tester;
    QTest::qExec(&tester);
    int answer = 0;
    UniqueList* listObject = new UniqueList();
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
                try
                {
                    listObject->addCarefully(value);
                }
                catch(AddingError error)
                {
                    printf("Such value is already in the list\n");
                }

                break;
            }
            case 2:
            {
                int value = 0;
                printf("What value?\n");
                scanf("%d", &value);
                try
                {
                    listObject->removeCarefully(value);
                }
                catch (DeletingError error)
                {
                    printf("%d is not found", value);
                }

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
