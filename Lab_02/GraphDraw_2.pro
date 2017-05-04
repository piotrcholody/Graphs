#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T20:02:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphDraw_2
TEMPLATE = app


SOURCES += main.cpp\
        graphdraw2.cpp \
    insertdatawindow.cpp \
    grafrysuj.cpp \
    ggenerator.cpp \
    ggeneratorve.cpp \
    ggeneratork.cpp \
    IncidenceMatrix.cpp \
    AdjacencyList.cpp \
    regGraphGen.cpp \
    randomize.cpp

HEADERS  += graphdraw2.h \
    insertdatawindow.h \
    grafrysuj.h \
    ggenerator.h \
    ggeneratorve.h \
    ggeneratork.h \
    IncidenceMatrix.h \
    AdjacencyList.h \
    connectionmatrix.h \
    connected_components.h \
    euler.h \
    hamiltonian.h \
    main.h \
    MyExceptions.h \
    randomization.h \
    regGraphGen.h \
    randomize.h

FORMS    += graphdraw2.ui \
    insertdatawindow.ui \
    ggenerator.ui \
    ggeneratorve.ui \
    ggeneratork.ui \
    randomize.ui

DISTFILES +=
