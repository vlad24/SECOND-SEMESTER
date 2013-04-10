#include <QtGui/QApplication>
#include "NormalCalculatorWidget.h"
#include "NormalCalculatorTester.h"

int main(int argc, char *argv[])
{
    NormalCalculatorTester tester;
    QTest::qExec(&tester);
    QApplication a(argc, argv);
    NormalCalculatorWidget w;
    w.show();
    
    return a.exec();
}
