#ifndef BARMOVER_H
#define BARMOVER_H

#include <QWidget>

namespace Ui {
class BarMover;
}

class BarMover : public QWidget
{
    Q_OBJECT
    
public:
    explicit BarMover(QWidget *parent = 0);
    ~BarMover();
    
private:
    Ui::BarMover *ui;
};

#endif // BARMOVER_H
