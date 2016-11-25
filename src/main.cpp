#include "glut_thread.h"
#include "mainwindow.h"

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	GLUT_Thread t;
	t.start();

	QApplication a(argc, argv);
	MainWindow w(&t);
	w.show();
	return a.exec();
}
