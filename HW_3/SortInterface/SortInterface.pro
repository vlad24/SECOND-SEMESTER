TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += core
CONFIG += qtestlib

SOURCES += main.cpp \
    HeapSorter.cpp \
    QuickSorter.cpp \
    ShellSorter.cpp \
    InsertSorter.cpp \
    BubbleSorter.cpp \
    SortBattler.cpp

HEADERS += \
    SortInterface.h \
    HeapSorter.h \
    QuickSorter.h \
    ShellSorter.h \
    InsertSorter.h \
    BubbleSorter.h \
    SortingTester.h \
    SortBattler.h

