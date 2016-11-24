#ifndef _WIN_H_
#define _WIN_H_

#include <QApplication>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "glut_thread.h"

class Win : public QMainWindow{
	Q_OBJECT
public:
	explicit Win(GLUT_Thread *t, QWidget *parent = 0);
private:
	GLUT_Thread *glut;
};

#endif
