TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    SpiralPrinterFile.cpp \
    SpiralPrinterConsole.cpp \
    SpiralMaker.cpp

HEADERS += \
    SpiralPrinterFile.h \
    SpiralPrinterConsole.h \
    SpiralMaker.h \
    SpiralTester.h
