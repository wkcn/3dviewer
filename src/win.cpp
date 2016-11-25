#include "win.h"
Win::Win(GLUT_Thread *t, QWidget *parent):QMainWindow(parent), glut(t), ui(new Ui::MainWindow){
	//resize(300, 800);
	ui->setupUi(this);
	move(300 + 800, 100);
}
