#pragma once

#include <QWidget>
#include <qstring.h>
#include "Calculator.h"

namespace Ui {
class NormalCalculatorWidget;
}

class NormalCalculatorWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit NormalCalculatorWidget(QWidget *parent = 0);
    ~NormalCalculatorWidget();
public slots:
    void numberOrDotPushed(QString numberSymbol);
    void signPushed(QString operationSymbol);
    void equalsPushed();
    //! Screen of a calculator is cleaned with all the history of clculating before that
    void reset();
private:
    Ui::NormalCalculatorWidget *ui;

    QString operand1;
    QString operand2;
    QString operation;
    //! Value which shows what operand a user is filling
    bool firstOperandIsChanging;
    //! Value which shows a state when a user can change an arithmetic sign
    bool signIsChanging;
    //! Value which is true when all necessary data for calculating is got
    bool readyToCalculate;

    //! A function which indicates double numbers that can be printed as integers
    QString avoidIntWithZeroes(QString &number) const;
    //! An object that do all arithmenic operations
    Calculator calculator;
};
