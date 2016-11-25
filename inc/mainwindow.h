#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QApplication>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "glut_thread.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow{
	Q_OBJECT
public:
	explicit MainWindow(GLUT_Thread *t, QWidget *parent = 0);
private:
	GLUT_Thread *glut;
	Ui::MainWindow *ui;
private slots:
	void SelectViewMode(int);
};

#endif
