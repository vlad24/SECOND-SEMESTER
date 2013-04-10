TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    TreeNodeSign.cpp \
    TreeNodeOperand.cpp \
    TreeNode.cpp \
    Tree.cpp \
    SymbolMaster.cpp \
    StringValidator.cpp

HEADERS += \
    TreeNodeSign.h \
    TreeNodeOperand.h \
    Tree.h \
    TreeNode.h \
    SymbolMaster.h \
    TreeTester.h \
    StringValidator.h
