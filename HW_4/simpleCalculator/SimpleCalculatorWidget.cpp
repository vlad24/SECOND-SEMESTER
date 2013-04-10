#include "SimpleCalculatorWidget.h"
#include "ui_simpleCalculatorWidget.h"


SimpleCalculatorWidget::SimpleCalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simpleCalculatorWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->number1, SIGNAL(valueChanged(int)), this, SLOT(recalculate()));
    QObject::connect(ui->number2, SIGNAL(valueChanged(int)), this, SLOT(recalculate()));
    QObject::connect(ui->operation, SIGNAL(currentIndexChanged(QString)), this, SLOT(recalculate()));
    QObject::connect(this, SIGNAL(resultChanged(QString)), ui->result, SLOT(setText(QString)));
}

SimpleCalculatorWidget::~SimpleCalculatorWidget()
{
    delete ui;
}

void SimpleCalculatorWidget::recalculate()
{
    double newResult = recalculator.makeOperation(ui->number1->value(), ui->number2->value(), ui->operation->currentText());
    QString resultString = QString::number(newResult,'f');
    emit resultChanged(resultString);
}

