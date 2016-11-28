#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T09:46:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -Wno-unused-parameter -std=c++11 -Iinc
QMAKE_LFLAGS += -lGLU

TARGET = qtgl
TEMPLATE = app


SOURCES += src/*.cpp

HEADERS  += inc/*.h

FORMS    += ui/mainwindow.ui
