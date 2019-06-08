#!/bin/sh
QT_VERSION=0.3.0
export QT_VERSION
QT_VER=0.3
export QT_VER
QT_VERSION_TAG=030
export QT_VERSION_TAG
QT_INSTALL_DOCS=C:/Qt/Docs/Qt-5.10.0
export QT_INSTALL_DOCS
BUILDDIR=C:/Users/areeves/Documents/_A_ResearchProjects/Tools/QtXlsxWriter/src/xlsx
export BUILDDIR
exec 'C:\Qt\5.10.0\mingw53_32\bin\qdoc.exe' "$@"
