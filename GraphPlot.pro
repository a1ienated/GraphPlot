#-------------------------------------------------
#
# Project created by QtCreator 2019-08-12T09:19:40
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphPlot
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        graphplot.cpp \
    qcustomplot.cpp \
    MixedSimple2DGraph.cpp \
    generatedatathread.cpp

HEADERS  += graphplot.h \
    MixedSimple2DGraph.h \
    qcustomplot.h \
    generatedatathread.h

FORMS    += graphplot.ui
