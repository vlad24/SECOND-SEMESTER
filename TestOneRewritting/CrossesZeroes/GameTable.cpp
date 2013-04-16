#include "GameTable.h"
#include "ui_gametable.h"
#include <QDebug>
#include <QSignalMapper>
int pushings = 0;

GameTable::GameTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTable)
{
    ui->setupUi(this);

    for (int i = 0; i <= 2 ; i++)
        horizontalLines[i] = 0;
    for (int i = 0; i <= 2 ; i++)
        verticalLines[i] = 0;
    for (int i = 0; i <=1; i++)
        diagonals[i] = 0;

    QSignalMapper* mapper = new QSignalMapper;

    connect(ui->button1, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button1, SIGNAL(clicked(bool)), ui->button1, SLOT(setDisabled(bool)));
    connect(ui->button1, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button1, 1);

    connect(ui->button2, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button2, SIGNAL(clicked(bool)), ui->button2, SLOT(setDisabled(bool)));
    connect(ui->button2, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button2, 2);

    connect(ui->button3, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button3, SIGNAL(clicked(bool)), ui->button3, SLOT(setDisabled(bool)));
    connect(ui->button3, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button3, 3);

    connect(ui->button4, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button4, SIGNAL(clicked(bool)), ui->button4, SLOT(setDisabled(bool)));
    connect(ui->button4, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button4, 4);

    connect(ui->button5, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button5, SIGNAL(clicked(bool)), ui->button5, SLOT(setDisabled(bool)));
    connect(ui->button5, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button5, 5);

    connect(ui->button6, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button6, SIGNAL(clicked(bool)), ui->button6, SLOT(setDisabled(bool)));
    connect(ui->button6, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button6, 6);

    connect(ui->button7, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button7, SIGNAL(clicked(bool)), ui->button7, SLOT(setDisabled(bool)));
    connect(ui->button7, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button7, 7);

    connect(ui->button8, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button8, SIGNAL(clicked(bool)), ui->button8, SLOT(setDisabled(bool)));
    connect(ui->button8, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button8, 8);

    connect(ui->button9, SIGNAL(clicked(bool)), this, SLOT(changeTextOfButton()));
    connect(ui->button9, SIGNAL(clicked(bool)), ui->button9, SLOT(setDisabled(bool)));
    connect(ui->button9, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ui->button9, 9);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(observeGame(int)));
    connect(this, SIGNAL(gameOver()), this, SLOT(finishGame()));
}

GameTable::~GameTable()
{
    delete ui;
}

void GameTable::changeTextOfButton()
{
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    if (pushings % 2 == 0)
        button->setText("X");
    else
        button->setText("O");
    pushings++;
}

void GameTable::observeGame(int id)
{
    int y = (id - 1) / 3;
    int x = (id - 1) % 3;
    int input = pushings % 2;
    if (input == 0)
        input--;
    if (x == y)
    {
        diagonals[0] += input;
        if (diagonals[0] == -3 || diagonals[0] == 3)
            emit gameOver();
    }
    if (x + y == 2)
    {
        diagonals[1] += input;
        if (diagonals[1] == -3 || diagonals[1] == 3)
            emit gameOver();
    }
    horizontalLines[y] += input;
    verticalLines[x] += input;
    if (horizontalLines[y] == -3 || horizontalLines[y] == 3)
        emit gameOver();
    if (verticalLines[x] == -3 || verticalLines[x] == 3)
        emit gameOver();
}

void GameTable::finishGame()
{
    if (pushings % 2 == 0)
        ui->label->setText("O win");
    else
        ui->label->setText("X win");
    ui->button1->setDisabled(true);
    ui->button2->setDisabled(true);
    ui->button3->setDisabled(true);
    ui->button4->setDisabled(true);
    ui->button5->setDisabled(true);
    ui->button6->setDisabled(true);
    ui->button7->setDisabled(true);
    ui->button8->setDisabled(true);
    ui->button9->setDisabled(true);
}
