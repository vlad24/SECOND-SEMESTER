#include <QtGui/QApplication>
#include <QDebug>
#include "SimpleCalculatorWidget.h"
#include "CalculatorTester.h"

int main(int argc, char *argv[])
{
    CalculatorTester tester;
    QTest::qExec(&tester);

    QApplication a(argc, argv);
    SimpleCalculatorWidget w;
    w.show();
    return a.exec();
}
