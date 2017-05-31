#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T10:06:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tableviewTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Delegate/CCheckBoxHeaderView.cpp \
    ModelData/CModelData.cpp \
    Delegate/CPixBtnDelegate.cpp \
    Delegate/CSpinBoxDelegate.cpp \
    Delegate/CComboBoxDelegate.cpp \
    Delegate/CCLineEditDelegate.cpp \
    Delegate/CComboCheckBoxDelegate.cpp \
    Delegate/CProcessDelegate.cpp \
    Delegate/CDateTimeDelegate.cpp

HEADERS  += mainwindow.h \
    Delegate/CCheckBoxHeaderView.h \
    ModelData/CModelData.h \
    Delegate/CPixBtnDelegate.h \
    Delegate/CSpinBoxDelegate.h \
    Delegate/CComboBoxDelegate.h \
    Delegate/CCLineEditDelegate.h \
    Delegate/CComboCheckBoxDelegate.h \
    Delegate/CProcessDelegate.h \
    Delegate/CDateTimeDelegate.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
