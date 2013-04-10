#include "NormalCalculatorWidget.h"
#include "ui_NormalCalculatorWidget.h"
#include "qsignalmapper.h"
#include <stdio.h>

NormalCalculatorWidget::NormalCalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalCalculatorWidget)
{
    ui->setupUi(this);

    operand1 = "";
    operand2 = "";
    firstOperandIsChanging = true;
    signIsChanging = false;
    readyToCalculate = false;

    QSignalMapper* numberDotMapper = new QSignalMapper();
    connect(ui->button0, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button0, "0");

    connect(ui->button1, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button1, "1");

    connect(ui->button2, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button2, "2");

    connect(ui->button3, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button3, "3");

    connect(ui->button4, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button4, "4");

    connect(ui->button5, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button5, "5");

    connect(ui->button6, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button6, "6");

    connect(ui->button7, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button7, "7");

    connect(ui->button8, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button8, "8");

    connect(ui->button9, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->button9, "9");

    connect(ui->buttonDot, SIGNAL(clicked()), numberDotMapper, SLOT(map()));
    numberDotMapper->setMapping(ui->buttonDot, ".");
    //
    QSignalMapper* signMapper = new QSignalMapper();
    connect(ui->buttonPlus, SIGNAL(clicked()), signMapper, SLOT(map()));
    signMapper->setMapping(ui->buttonPlus, "+");

    connect(ui->buttonMinus, SIGNAL(clicked()), signMapper, SLOT(map()));
    signMapper->setMapping(ui->buttonMinus, "-");

    connect(ui->buttonMult, SIGNAL(clicked()), signMapper, SLOT(map()));
    signMapper->setMapping(ui->buttonMult, "*");

    connect(ui->buttonDiv, SIGNAL(clicked()), signMapper, SLOT(map()));
    signMapper->setMapping(ui->buttonDiv, "/");
    //
    QSignalMapper* equalsMapper = new QSignalMapper();
    connect(ui->buttonEquals, SIGNAL(clicked()), equalsMapper, SLOT(map()));
    equalsMapper->setMapping(ui->buttonEquals, "=");

    QSignalMapper* resetMapper = new QSignalMapper();
    connect(ui->buttonReset, SIGNAL(clicked()), resetMapper, SLOT(map()));
    resetMapper->setMapping(ui->buttonReset, "C");

    connect(numberDotMapper, SIGNAL(mapped(QString)), this, SLOT(numberOrDotPushed(QString)));
    connect(signMapper, SIGNAL(mapped(QString)), this, SLOT(signPushed(QString)));
    connect(equalsMapper, SIGNAL(mapped(QString)), this, SLOT(equalsPushed()));
    connect(resetMapper,SIGNAL(mapped(QString)), this, SLOT(reset()));
}

NormalCalculatorWidget::~NormalCalculatorWidget()
{
    delete ui;
}

void NormalCalculatorWidget::numberOrDotPushed(QString numberSymbol)
{
    if (firstOperandIsChanging)
    {
        operand1.append(numberSymbol);
        ui->resultBox->setText(operand1);
    }
    else
    {
        signIsChanging = false;
        operand2.append(numberSymbol);
        ui->resultBox->setText(operand2);
        readyToCalculate = true;
    }
}

QString NormalCalculatorWidget::avoidIntWithZeroes(QString &number) const
{
    int i = 0;
    while (number.at(i).toAscii() != '.')
    {
        if (i < number.length() - 1)
            i++;
        else
            break;
    }
    int zeroesChain = 0;
    const int enoughZeroAmount = 4;
    if (number.at(i).toAscii() == '.')
    {
        int dotPos = i;
        ++i;
        printf("%c" , number.at(i).toAscii());
        while ((number.at(i).toAscii() == '0')&&(zeroesChain < enoughZeroAmount)&&(i < number.length()))
        {
            zeroesChain++;
            i++;
        }
        if (zeroesChain == enoughZeroAmount)
        {
            number.truncate(dotPos);
            return number;
        }
        else
        {
            number.truncate(dotPos + enoughZeroAmount + 1);
            return number;
        }
    }
    else
    {
        return number;
    }
}

void NormalCalculatorWidget::equalsPushed()
{
    if (!firstOperandIsChanging)
    {
        QString resultString = "";
        if (readyToCalculate)
        {
            resultString = calculator.makeOperation(operand1, operand2, operation);
            resultString = avoidIntWithZeroes(resultString);
            ui->resultBox->setText(resultString);

            operand1 = resultString;
            operand2 = "";

            firstOperandIsChanging = false;
            signIsChanging = true;
            readyToCalculate = false;
        }
    }
}
void NormalCalculatorWidget::signPushed(QString operationSymbol)
{
        if (firstOperandIsChanging)
        {
            firstOperandIsChanging = false;
            operation = operationSymbol;
            signIsChanging = true;
            ui->currentSign->setText(operation);
        }
        else
        {
            if (signIsChanging)
            {
                operation = operationSymbol;
                ui->currentSign->setText(operation);
            }
            else
            {
                equalsPushed();
                operation = operationSymbol;
                ui->currentSign->setText(operation);
                signIsChanging = true;
            }
        }
}

void NormalCalculatorWidget::reset()
{
    operand1 = "";
    operand2 = "";
    operation = "";
    ui->resultBox->setText("");
    ui->currentSign->setText("");
    firstOperandIsChanging = true;
    signIsChanging = false;
}

