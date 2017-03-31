#-------------------------------------------------
#
# Project created by QtCreator 2015-07-10T13:39:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testView
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    itemview.cpp \
    comissao.cpp \
    itemTopico.cpp

HEADERS  += mainwindow.h \
    itemview.h \
    comissao.h \
    itemTopico.h

FORMS    += mainwindow.ui \
    itemview.ui \
    itemTopico.ui
