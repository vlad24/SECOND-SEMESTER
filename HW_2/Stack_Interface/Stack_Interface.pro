TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    StringCalculator.cpp \
    ArrayStack.cpp \
    PointerStack.cpp

HEADERS += \
    StringCalculator.h \
    StackInterface.h \
    ArrayStack.h \
    PointerStack.h \
    StackTester.h

