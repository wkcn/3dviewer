#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T09:46:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11 -Iinc
QMAKE_LFLAGS += -lGLU

TARGET = qtgl
TEMPLATE = app

HEADERS += \
    inc/loadobj.h \
    inc/mainwindow.h \
    inc/model.h \
    inc/objshape.h \
    inc/qtgl.h \
    inc/shape.h

SOURCES += \
    src/loadobj.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/model.cpp \
    src/objshape.cpp \
    src/qtgl.cpp \
    src/shape.cpp

FORMS += \
    ui/mainwindow.ui \
    ui/parbar.ui
