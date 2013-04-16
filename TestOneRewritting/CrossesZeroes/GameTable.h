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
    void changeTextOfButton();
    void observeGame(int id);
    void finishGame();
signals:
    void gameOver();
public:
    explicit GameTable(QWidget *parent = 0);
    ~GameTable();
    
private:
    Ui::GameTable *ui;
    int table[3][3];
    int diagonals[2];
    int horizontalLines[3];
    int verticalLines[3];

};

