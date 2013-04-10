#include "BarMover.h"
#include "ui_BarMover.h"

BarMover::BarMover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BarMover)
{
    ui->setupUi(this);
    connect(ui->verticalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

BarMover::~BarMover()
{
    delete ui;
}
