TARGET = mergecells

#include(../../../src/xlsx/qtxlsx.pri)
QT += xlsx

TARGET = numberformat
CONFIG   += console install_ok
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
