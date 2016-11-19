#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <string>
#include "drawobj.h"
using namespace std;

Model md = loadObj("bb.obj");
void Display(){
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawModel(md);

	glutSwapBuffers();
}

void Idle(){
	Display();
}

void Reshape(int w, int h){
}

void Keyboard(unsigned char key, int x, int y){
}


int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("3dviewer");


	glutDisplayFunc(&Display);
	glutIdleFunc(&Idle);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(&Keyboard);

	glutMainLoop();
	return 0;
}
