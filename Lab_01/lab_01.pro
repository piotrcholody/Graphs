#-------------------------------------------------
#
# Project created by QtCreator 2017-03-26T23:26:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_01
TEMPLATE = app


SOURCES += main.cpp\
    adjacencylist.cpp \
    incidencematrix.cpp \
    gdraw.cpp \
    ggenerator.cpp \
    ggeneratorve.cpp \
    grafrysuj.cpp

HEADERS  += \
    connectionmatrix.h \
    graph.h \
    incidencematrix.h \
    adjacencylist.h \
    gdraw.h \
    ggenerator.h \
    ggeneratorve.h \
    grafrysuj.h

FORMS    += \
    gdraw.ui \
    ggenerator.ui \
    ggeneratorve.ui

RESOURCES +=
