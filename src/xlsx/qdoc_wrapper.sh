#!/bin/sh
QT_VERSION=0.3.0
export QT_VERSION
QT_VER=0.3
export QT_VER
QT_VERSION_TAG=030
export QT_VERSION_TAG
QT_INSTALL_DOCS=C:/Qt/Docs/Qt-5.7
export QT_INSTALL_DOCS
exec 'C:\Qt\5.7\mingw53_32\bin\qdoc.exe' "$@"
