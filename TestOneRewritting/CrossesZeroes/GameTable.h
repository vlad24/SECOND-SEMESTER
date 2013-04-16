#pragma once
#include <QWidget>
#include <QPushButton>

namespace Ui {
class GameTable;
}

class GameTable : public QWidget
{
    Q_OBJECT    
public slots:
    void changeTextOfButton(QPushButton *button);
public:
    explicit GameTable(QWidget *parent = 0);
    ~GameTable();
    
private:
    Ui::GameTable *ui;

};

