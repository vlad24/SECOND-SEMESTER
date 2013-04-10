#include <QtGui/QApplication>
#include "BarMover.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarMover w;
    w.show();
    
    return a.exec();
}
