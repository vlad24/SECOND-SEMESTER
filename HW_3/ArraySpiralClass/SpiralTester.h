#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "SpiralPrinterConsole.h"
#include "SpiralPrinterFile.h"

class SpiralTester : public QObject
{
    Q_OBJECT
public:
    explicit SpiralTester(QObject *parent = 0): QObject(parent){}

private slots:

    void init()
    {
        file = fopen("testFile.txt", "w");
    }

    void testCreation()
    {
        cPrinter = new SpiralPrinterConsole(3);
        delete cPrinter;
        fPrinter = new SpiralPrinterFile(file, 7);
        delete fPrinter;
    }
    void testGoingSpiral()
    {
        int** a = new int*[3];
        for (int i = 0; i < 3; i++)
            a[i] = new int [3];
        for (int i = 0; i < 3; i++)
            for (int j = 0 ; j < 3; j++)
                a[i][j] = i + j;
        cPrinter = new SpiralPrinterConsole(3);
        cPrinter->spiralPrint(a);
        delete cPrinter;
        printf("Expected:2 3 2 1 0 1 2 3 4\n");
        fPrinter = new SpiralPrinterFile(file, 3);
        fPrinter->spiralPrint(a);
        delete fPrinter;
        printf("File has changed\n");
    }
    void cleanUp()
    {
        fclose(file);
    }

private:
    SpiralPrinterConsole* cPrinter;
    SpiralPrinterFile* fPrinter;
    FILE* file;
};
