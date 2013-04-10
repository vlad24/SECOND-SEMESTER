#-------------------------------------------------
#
# Project created by QtCreator 2013-03-12T21:07:17
#
#-------------------------------------------------

QT       += core gui

TARGET = simpleCalculator
TEMPLATE = app
CONFIG += qtestlib

SOURCES += main.cpp \
    SimpleCalculatorWidget.cpp \
    Calculator.cpp

HEADERS  += \
    SimpleCalculatorWidget.h \
    Calculator.h \
    CalculatorTester.h

FORMS    += \
    simpleCalculatorWidget.ui
