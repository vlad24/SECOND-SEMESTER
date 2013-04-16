#include "GameTable.h"
#include "ui_gametable.h"
#include "QSignalMapper"

int pushings = 0;

GameTable::GameTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTable)
{
    ui->setupUi(this);
    QSignalMapper* buttonMapper = new QSignalMapper();

    connect(ui->button1, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button1, ui->button1);
    connect(ui->button1, SIGNAL(clicked(bool)), ui->button1, SLOT(setDisabled(bool)));

    connect(ui->button2, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button2, ui->button2);
    connect(ui->button2, SIGNAL(clicked(bool)), ui->button2, SLOT(setDisabled(bool)));

    connect(ui->button3, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button3, ui->button3);
    connect(ui->button3, SIGNAL(clicked(bool)), ui->button3, SLOT(setDisabled(bool)));

    connect(ui->button4, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button4, ui->button4);
    connect(ui->button4, SIGNAL(clicked(bool)), ui->button4, SLOT(setDisabled(bool)));

    connect(ui->button5, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button5, ui->button5);
    connect(ui->button5, SIGNAL(clicked(bool)), ui->button5, SLOT(setDisabled(bool)));

    connect(ui->button6, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button6, ui->button6);
    connect(ui->button6, SIGNAL(clicked(bool)), ui->button6, SLOT(setDisabled(bool)));

    connect(ui->button7, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button7, ui->button7);
    connect(ui->button7, SIGNAL(clicked(bool)), ui->button7, SLOT(setDisabled(bool)));

    connect(ui->button8, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    buttonMapper->setMapping(ui->button8, ui->button8);
    connect(ui->button8, SIGNAL(clicked(bool)), ui->button8, SLOT(setDisabled(bool)));

    connect(ui->button9, SIGNAL(clicked()), buttonMapper, SLOT(map()));
    connect(ui->button9, SIGNAL(clicked(bool)), ui->button9, SLOT(setDisabled(bool)));
    buttonMapper->setMapping(ui->button9, ui->button9);


    connect(buttonMapper, SIGNAL(mapped(QObject*)), this, SLOT(changeTextOfButton(QPushButton*)));
}

GameTable::~GameTable()
{
    delete ui;
}

void GameTable::changeTextOfButton(QPushButton* button)
{
    if (pushings % 2 == 0)
        button->setText("X");
    else
        button->setText("O");
    pushings++;
}
