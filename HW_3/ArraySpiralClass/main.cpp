#include <stdio.h>
#include "SpiralPrinterConsole.h"
#include "SpiralPrinterFile.h"
#include "SpiralTester.h"

enum userChoice
{
    consoleChoice, fileChoice
};

int main()
{
    SpiralTester tester;
    QTest::qExec(&tester);
    /////
    int sideLength = 1;
    printf("Enter the length of side of the array : ");
    scanf("%d", &sideLength);
    if (sideLength % 2 == 1)
    {
        int** array = new int*[sideLength];
        for (int u = 0; u < sideLength; u++)
        {
            array[u] = new int[sideLength];
        }

        int i = 0;
        int j = 0;

        printf("Initialize the array by strings(use gaps between elements)\n") ;
        for (i = 0 ; i < sideLength ; i++)
            for (j = 0 ; j < sideLength ; j++)
            {
                scanf("%d", &(array[i][j]));
            }

        printf("Where would you like to print your spiral?\n");
        printf("0 - to console, 1 - to file\n");
        int answer = 0;
        scanf("%d", &answer);
        switch (answer)
        {
        case consoleChoice :
        {
            SpiralMaker* printer = new SpiralPrinterConsole(sideLength);
            printer->spiralPrint(array);
            delete printer;
            break;
        }
        case fileChoice:
        {
            FILE* userFile = fopen("spiral.txt","w");
            SpiralMaker* printer = new SpiralPrinterFile(userFile, sideLength);
            printer->spiralPrint(array);
            delete printer;
            fclose(userFile);
            break;
        }
        }
        //Delete the array
        for (int u = 0; u < sideLength; u++)
        {
            delete[] array[u];
        }
        delete[] array;
        return 0;
    }
    else
    {
        printf("Error\n");
    }
    getc(stdin);
}

