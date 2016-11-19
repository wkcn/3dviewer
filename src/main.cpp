#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <string>
#include "loadobj.h"
#include "model.h"
using namespace std;

Model md = loadObj("bb.obj");

double CAM_X = 0, CAM_Y = 0;
double CAM_Z = 6;
double CAM_V = 0.3;
double CAM_ROTATE = 0;
double CAM_ROTATE_X = 0;
double CAM_ROTATE_Y = 0;
double CAM_ROTATE_A = 5;


void SetLight(){
	const GLfloat am = 0.0f;
	const GLfloat l = 1.0f;
	GLfloat light_position[] = {3,3,3,1.0f};
	GLfloat light_ambient[] = {am, am, am, 1.0f};
	GLfloat light_diffuse[] = {l,l,l,l};
	GLfloat light_specular[] = {l,l,l,l};
	GLuint lid = GL_LIGHT0;
	glLightfv(lid, GL_POSITION, light_position);
	glLightfv(lid, GL_AMBIENT, light_ambient); // 最终光线
	glLightfv(lid, GL_DIFFUSE, light_diffuse); // 漫反射
	glLightfv(lid, GL_SPECULAR, light_specular); // 镜面反射
	glEnable(lid);
}

void Display(){
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(CAM_X, CAM_Y, CAM_Z, CAM_X, CAM_Y, 0, 0, 1, 0);
	glRotated(CAM_ROTATE, 0, 0, 1);
	glRotated(CAM_ROTATE_X, 1, 0, 0);
	glRotated(CAM_ROTATE_Y, 0, 1, 0);



	// 线框模型
	//md.DrawLines();
	
	// 面模型
	SetLight();
	md.Draw();

	glutSwapBuffers();
}

void Idle(){
	Display();
}

void Reshape(int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);   
	glMatrixMode (GL_PROJECTION);  
	glLoadIdentity ();  
	gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 0, 10.0);  
}

void Keyboard(unsigned char key, int x, int y){
	switch (key){
		case 'w':CAM_Y += CAM_V;break;
		case 's':CAM_Y -= CAM_V;break;
		case 'a':CAM_X -= CAM_V;break;
		case 'd':CAM_X += CAM_V;break;
		case 'z':CAM_Z += CAM_V;break;
		case 'c':CAM_Z -= CAM_V;break;
		case 'q':CAM_ROTATE -= CAM_ROTATE_A;break;
		case 'e':CAM_ROTATE += CAM_ROTATE_A;break;
		case 'i':CAM_ROTATE_X += CAM_ROTATE_A;break;
		case 'o':CAM_ROTATE_X -= CAM_ROTATE_A;break;
		case 'j':CAM_ROTATE_Y += CAM_ROTATE_A;break;
		case 'k':CAM_ROTATE_Y -= CAM_ROTATE_A;break;
	}
}


void Init(){
	//打开2D贴图状态
	glEnable(GL_TEXTURE_2D);
	//混色
	/*
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);

	//抗锯齿
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	glHint(GL_FOG_HINT, GL_NICEST);
	*/

	/*
	GLfloat light_a[4] = {0.1,0.1,0.1,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_a);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	*/
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("3dviewer");

	Init();
	glutDisplayFunc(&Display);
	glutIdleFunc(&Idle);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(&Keyboard);

	glutMainLoop();
	return 0;
}
