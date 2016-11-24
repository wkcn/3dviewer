#include "glut_thread.h"
#include "win.h"

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	GLUT_Thread t;
	t.start();

	QApplication a(argc, argv);
	Win w(&t);
	w.show();
	return a.exec();
}
