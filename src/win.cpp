#include "win.h"
Win::Win(GLUT_Thread *t, QWidget *parent):QMainWindow(parent), glut(t){
	this->resize(300, 800);
	this->move(300 + 800, 100);
}
