#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T20:33:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gomoku
TEMPLATE = app


SOURCES += \
    board.cpp \
    main.cpp \
    peoplevspeople.cpp \
    peoplevscomputer.cpp \
    gametype.cpp

HEADERS  += \
    board.h \
    peoplevspeople.h \
    peoplevscomputer.h \
    gametype.h

FORMS    += \
    gametype.ui

RC_ICONS= myicoo.ico
