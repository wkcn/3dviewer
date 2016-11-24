QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11 -g -pthread -Iinc -Wunused-parameter
QMAKE_LFLAGS += -lglut -lGL -lGLU -lfreeimage

TARGET = 3dviewer
TEMPLATE = app


SOURCES += src/*.cpp

HEADERS  += inc/*.h 
