TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    List.cpp \
    HashTable.cpp \
    CommonHasher.cpp \
    PolynomialHasher.cpp \
    BaseHasher.cpp

HEADERS += \
    List.h \
    Hasher.h \
    HashTable.h \
    ListTester.h \
    CommonHasher.h \
    PolynomialHasher.h \
    BaseHasher.h \
    HasherTester.h \
    HashTableTester.h

