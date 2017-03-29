#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T21:40:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JezykBlokowy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    connection.cpp \
    inputelement.cpp \
    outputelement.cpp \
    graphicsitem.cpp \
    ioelement.cpp \
    addition.cpp \
    itemfactory.cpp \
    itembuttonwidget.cpp \
    controller.cpp \
    additemfactory.cpp \
    mapper.cpp \
    subtractitemfactory.cpp \
    sumexpression.cpp \
    differenceexpression.cpp \
    inputexpression.cpp \
    outputexpression.cpp \
    inputitemfactory.cpp \
    outputitemfactory.cpp \
    arithmeticexpression.cpp \
    itemattributesdialog.cpp \
    itemconfig.cpp

HEADERS  += mainwindow.h \
    scene.h \
    connection.h \
    inputelement.h \
    outputelement.h \
    graphicsitem.h \
    iexpression.h \
    data.h \
    ioelement.h \
    addition.h \
    itemfactory.h \
    itembuttonwidget.h \
    controller.h \
    additemfactory.h \
    mapper.h \
    subtractitemfactory.h \
    sumexpression.h \
    differenceexpression.h \
    inputexpression.h \
    outputexpression.h \
    inputitemfactory.h \
    outputitemfactory.h \
    arithmeticexpression.h \
    itemattributesdialog.h \
    itemconfig.h

FORMS    += mainwindow.ui
