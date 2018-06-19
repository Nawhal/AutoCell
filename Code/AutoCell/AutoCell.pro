#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T19:39:23
#
#-------------------------------------------------

QT       += core gui
CONFIG   += Qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoCell
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += xml

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    cell.cpp \
    state.cpp \
    automaton.cpp \
    simulator.cpp \
    elementaryAutomaton.cpp \
    elementarySimulator.cpp \
    gameOfLifeAutomaton.cpp \
    dayAndNightAutomaton.cpp \
    xmlautomatondatamanager.cpp \
    configdayandnightautomatonwindow.cpp \
    configelementaryautomatonwindow.cpp \
    configgameoflifeautomatonwindow.cpp \
    mainwindow.cpp \
    simulationwindow.cpp \
    windowmanager.cpp \
    qtsimulator.cpp \
    qtelementarysimulator.cpp

HEADERS += \
    cell.h \
    state.h \
    automaton.h \
    simulator.h \
    elementaryAutomaton.h \
    elementarySimulator.h \
    gameOfLifeAutomaton.h \
    dayAndNightAutomaton.h \
    xmlautomatondatamanager.h \
    configdayandnightautomatonwindow.h \
    configelementaryautomatonwindow.h \
    configgameoflifeautomatonwindow.h \
    mainwindow.h \
    simulationwindow.h \
    windowmanager.h \
    qtsimulator.h \
    qtelementarysimulator.h

FORMS += \
    configdayandnightautomatonwindow.ui \
    configelementaryautomatonwindow.ui \
    configgameoflifeautomatonwindow.ui \
    mainwindow.ui \
    simulationwindow.ui
