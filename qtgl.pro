#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T09:46:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11 -Iinc -Ilibraries

TARGET = qtgl
TEMPLATE = app

unix{
QMAKE_LFLAGS += -lGLU
HEADERS += inc/*.h

SOURCES += src/*.cpp

FORMS += ui/*.ui
}

win32{

INCLUDEPATH += inc

HEADERS += \
    inc/loadobj.h \
    inc/mainwindow.h \
    inc/model.h \
    inc/objshape.h \
    inc/shape.h \
    inc/qtgl.h

SOURCES += \
    src/loadobj.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/model.cpp \
    src/objshape.cpp \
    src/shape.cpp  \
    src/qtgl.cpp

FORMS += \
    ui/mainwindow.ui
}

HEADERS +=

SOURCES +=
