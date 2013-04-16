#include <QtGui/QApplication>
#include "GameTable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameTable w;
    w.show();
    
    return a.exec();
}
