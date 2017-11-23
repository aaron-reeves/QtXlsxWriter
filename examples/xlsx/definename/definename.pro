TARGET = definename

#include(../../../src/xlsx/qtxlsx.pri)
QT+=xlsx

CONFIG   += console install_ok
CONFIG   -= app_bundle

SOURCES += main.cpp
