#include <Windows.h>
#include <GL\glut.h>
#include<math.h>
#include<stdio.h>


GLfloat x = 0.0f;										//图像平移分量
GLfloat z = 0.0f;
GLfloat y = 0.0f;
GLfloat tx = 1.0f;										//视图大小，控制缩放
GLfloat ty = 1.0f;
GLfloat tz = 1.0f;
GLfloat  oldmy, oldmx;									//鼠标按下的位置（x,y)
GLfloat deltax, deltay;									//释放后，x和y移动分量

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();										//push Matrix
	glRotatef(deltax, 0.0, 1.0, 0.0);					//x轴旋转
	glRotatef(deltay, 1.0, 0.0, 0.0);					//y轴旋转
	glTranslatef(x, y, z);
	glScalef(tx, ty, tz);

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

	glPopMatrix();
	glutSwapBuffers();
}

void Mouse(int button, int state, int x, int y) //处理鼠标点击  
{
	if (state == GLUT_DOWN) //第一次鼠标按下时,记录鼠标在窗口中的初始坐标  
		oldmx = x, oldmy = y;
}

void onMouseMove(int x, int y) //处理鼠标拖动  
{
	deltax += 360 * (x - oldmx) / 600;
	deltay += 360 * (y - oldmy) / 600;
	oldmx = x;
	oldmy = y;
}


void SpecialKeys(int key, int rx, int ry)
{
	if (key == GLUT_KEY_UP)
		y += 0.1f;

	if (key == GLUT_KEY_DOWN)
		y -= 0.1f;

	if (key == GLUT_KEY_LEFT)
		x -= 0.1f;

	if (key == GLUT_KEY_RIGHT)
		x += 0.1f;
	glutPostRedisplay();

}

void keyboard(unsigned char key, int m_x, int m_y)
{
	switch (key) {
	case '+':												//键盘中'+'就是'='
	case '=':
		tx = tx * 1.1;
		ty = ty * 1.1;
		tz = tz * 1.1;
		glutPostRedisplay();
		break;
	case '-':
		tx = tx / 1.1;
		ty = ty / 1.1;
		tz = tz / 1.1;
		glutPostRedisplay();
		break;
	}
}
void init()
{
	glEnable(GL_DEPTH_TEST);
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL");
	init();
	printf("方向键控制平移，+ - 控制缩放，鼠标控制旋转");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);  //设置不断调用显示函数  
	glutMouseFunc(Mouse);
	glutMotionFunc(onMouseMove);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
	return 0;
}
