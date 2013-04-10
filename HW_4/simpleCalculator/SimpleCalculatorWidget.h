#pragma once
#include <QWidget>
#include "Calculator.h"
#include <qstring.h>

namespace Ui {
class simpleCalculatorWidget;
}

class SimpleCalculatorWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit SimpleCalculatorWidget(QWidget *parent = 0);
    ~SimpleCalculatorWidget();
signals:
    //! A signal that is used to change the value in the box after recalculating
    void resultChanged(QString newResult);
public slots:
    //! When something is changed in argument- or operation- boxes we should recalculate the result
    void recalculate();
private:
    Ui::simpleCalculatorWidget *ui;
    //! A calculator that can do basic arithmetic
    Calculator recalculator;
};
