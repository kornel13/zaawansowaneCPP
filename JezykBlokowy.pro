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
    GraphicsItems/connection.cpp \
    GraphicsItems/inputelement.cpp \
    GraphicsItems/outputelement.cpp \
    GraphicsItems/graphicsitem.cpp \
    Factories/itemfactory.cpp \
    itembuttonwidget.cpp \
    controller.cpp \
    Factories/additemfactory.cpp \
    Common/mapper.cpp \
    Factories/subtractitemfactory.cpp \
    Expressions/sumexpression.cpp \
    Expressions/differenceexpression.cpp \
    Expressions/inputexpression.cpp \
    Expressions/outputexpression.cpp \
    Factories/inputitemfactory.cpp \
    Factories/outputitemfactory.cpp \
    Expressions/arithmeticexpression.cpp \
    itemattributesdialog.cpp \
    Common/itemconfig.cpp \
    Common/itemnameprovider.cpp \
    Data/doubleseries.cpp

HEADERS  += mainwindow.h \
    scene.h \
    GraphicsItems/connection.h \
    GraphicsItems/inputelement.h \
    GraphicsItems/outputelement.h \
    GraphicsItems/graphicsitem.h \
    Expressions/iexpression.h \
    Data/data.h \
    Factories/itemfactory.h \
    itembuttonwidget.h \
    controller.h \
    Factories/additemfactory.h \
    Common/mapper.h \
    Factories/subtractitemfactory.h \
    Expressions/sumexpression.h \
    Expressions/differenceexpression.h \
    Expressions/inputexpression.h \
    Expressions/outputexpression.h \
    Factories/inputitemfactory.h \
    Factories/outputitemfactory.h \
    Expressions/arithmeticexpression.h \
    itemattributesdialog.h \
    Common/itemconfig.h \
    Common/itemnameprovider.h \
    Data/doubleseries.h

FORMS    += mainwindow.ui
