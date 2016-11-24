#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <string>
#include "loadobj.h"
#include "model.h"
using namespace std;

Model md = loadObj("model/wolverine_obj.obj");


GLfloat CAM_X = 0.0f;										//图像平移分量
GLfloat cam_z = 0.0f;
GLfloat CAM_Y = 0.0f;
GLfloat CAM_TX = 1.0f;										//视图大小，控制缩放
GLfloat CAM_TY = 1.0f;
GLfloat CAM_TZ = 1.0f;
GLfloat CAM_OLDMY, CAM_OLDMX;									//鼠标按下的位置（x,y)
GLfloat CAM_DELTAX, CAM_DELTAY;									//释放后，x和y移动分量

void SetLight(){
	const GLfloat am = 0.0f;
	const GLfloat l = 0.01f;
	GLfloat light_position[] = {0,0,-1,0.0f};
	GLfloat light_ambient[] = {am, am, am, 1.0f};
	GLfloat light_diffuse[] = {l,l,l,l};
	GLfloat light_specular[] = {l,l,l,l};
	GLuint lid = GL_LIGHT0;
	glLightfv(lid, GL_POSITION, light_position);
	glLightfv(lid, GL_AMBIENT, light_ambient); // 最终光线
	glLightfv(lid, GL_DIFFUSE, light_diffuse); // 漫反射
	glLightfv(lid, GL_SPECULAR, light_specular); // 镜面反射
	glEnable(lid);
	glEnable(GL_LIGHTING);
}

void DrawCube(){

	glBegin(GL_QUADS);									// Draw A Quad
		glColor3f(0.0f, 1.0f, 0.0f);					// Set The Color To Green
		glVertex3f(1.0f, 1.0f, -1.0f);					// Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, -1.0f);					// Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom Left Of The Quad (Top)
		glVertex3f(1.0f, 1.0f, 1.0f);					// Bottom Right Of The Quad (Top)
		glColor3f(1.0f, 0.5f, 0.0f);						// Set The Color To Orange
		glVertex3f(1.0f, -1.0f, 1.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f, -1.0f, 1.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f, -1.0f, -1.0f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f(1.0f, -1.0f, -1.0f);					// Bottom Right Of The Quad (Bottom)
		glColor3f(1.0f, 0.0f, 0.0f);						// Set The Color To Red
		glVertex3f(1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Front)
		glVertex3f(-1.0f, -1.0f, 1.0f);					// Bottom Left Of The Quad (Front)
		glVertex3f(1.0f, -1.0f, 1.0f);					// Bottom Right Of The Quad (Front)
		glColor3f(1.0f, 1.0f, 0.0f);						// Set The Color To Yellow
		glVertex3f(1.0f, -1.0f, -1.0f);					// Top Right Of The Quad (Back)
		glVertex3f(-1.0f, -1.0f, -1.0f);					// Top Left Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f, -1.0f);					// Bottom Left Of The Quad (Back)
		glVertex3f(1.0f, 1.0f, -1.0f);					// Bottom Right Of The Quad (Back)
		glColor3f(0.0f, 0.0f, 1.0f);						// Set The Color To Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f, -1.0f);					// Top Left Of The Quad (Left)
		glVertex3f(-1.0f, -1.0f, -1.0f);					// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f, -1.0f, 1.0f);					// Bottom Right Of The Quad (Left)
		glColor3f(1.0f, 0.0f, 1.0f);						// Set The Color To Violet
		glVertex3f(1.0f, 1.0f, -1.0f);					// Top Right Of The Quad (Right)
		glVertex3f(1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Right)
		glVertex3f(1.0f, -1.0f, 1.0f);					// Bottom Left Of The Quad (Right)
		glVertex3f(1.0f, -1.0f, -1.0f);					// Bottom Right Of The Quad (Right)
	glEnd();											// Done Drawing The Quad

}

void Display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	glRotatef(CAM_DELTAX, 0.0, 1.0, 0.0);					//x轴旋转
	glRotatef(CAM_DELTAY, 1.0, 0.0, 0.0);					//y轴旋转
	glTranslatef(CAM_X, CAM_Y, cam_z);
	glScalef(CAM_TX, CAM_TY, CAM_TZ);


	glPushMatrix();
	glTranslatef(30,0,20);
	SetLight();
	glPopMatrix();
	// 线框模型
	//md.DrawLines();
	
	// 面模型
	md.Draw();
	DrawCube();

	glPopMatrix();
	glutSwapBuffers();
}

void Idle(){
	Display();
}

void Reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SpecialKeys(int key, int x, int y){
	if (key == GLUT_KEY_UP)
		CAM_Y += 0.1f;

	if (key == GLUT_KEY_DOWN)
		CAM_Y -= 0.1f;

	if (key == GLUT_KEY_LEFT)
		CAM_X -= 0.1f;

	if (key == GLUT_KEY_RIGHT)
		CAM_X += 0.1f;
	glutPostRedisplay();
}


void Keyboard(unsigned char key, int x, int y){
	switch (key) {
	case '+':												//键盘中'+'就是'='
	case '=':
		CAM_TX = CAM_TX * 1.1;
		CAM_TY = CAM_TY * 1.1;
		CAM_TZ = CAM_TZ * 1.1;
		glutPostRedisplay();
		break;
	case '-':
		CAM_TX = CAM_TX / 1.1;
		CAM_TY = CAM_TY / 1.1;
		CAM_TZ = CAM_TZ / 1.1;
		glutPostRedisplay();
		break;
	}
}

void Mouse(int button, int state, int x, int y){ //处理鼠标点击
	if (state == GLUT_DOWN) //第一次鼠标按下时,记录鼠标在窗口中的初始坐标  
		CAM_OLDMX = x, CAM_OLDMY = y;
	if (button == 4){
		CAM_TX = CAM_TX / 1.1;
		CAM_TY = CAM_TY / 1.1;
		CAM_TZ = CAM_TZ / 1.1;
		glutPostRedisplay();
	}else if (button == 3){
		CAM_TX = CAM_TX * 1.1;
		CAM_TY = CAM_TY * 1.1;
		CAM_TZ = CAM_TZ * 1.1;
		glutPostRedisplay();
	}
}

void OnMouseMove(int x, int y){ //处理鼠标拖动  
	CAM_DELTAX += 360 * (x - CAM_OLDMX) / 600;
	CAM_DELTAY += 360 * (y - CAM_OLDMY) / 600;
	CAM_OLDMX = x;
	CAM_OLDMY = y;
}


void Init(){
	//打开2D贴图状态
	glEnable(GL_TEXTURE_2D);
	//混色
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

	// 环境光
	GLfloat light_a[4] = {0.2,0.2,0.2,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_a);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("3dviewer");

	Init();

	glutDisplayFunc(Display);
	glutIdleFunc(Idle);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeys);
	glutMouseFunc(Mouse);
	glutMotionFunc(OnMouseMove);

	glutMainLoop();
	return 0;
}
