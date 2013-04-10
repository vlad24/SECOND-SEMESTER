TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    RobotClass.cpp \
    RobotCommand.cpp \
    UsbCommand.cpp \
    TurnEngineCommand.cpp \
    TakeTemperatureCommand.cpp

HEADERS += \
    RobotClass.h \
    RobotCommand.h \
    TurnEngineCommand.h \
    TakeTemperatureCommand.h

