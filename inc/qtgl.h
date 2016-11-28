#ifndef QTGL_H
#define QTGL_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QWidget>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <string>
#include "loadobj.h"
#include "model.h"
#include "shape.h"

using namespace std;

enum VIEW_MODE{
	TEX_MODE, FACE_MODE, LINE_MODE, POINT_MODE
};


class QtGL : public QOpenGLWidget{
    Q_OBJECT
public:
    explicit QtGL(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
protected:
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void wheelEvent(QWheelEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
private:
	void SetLight();
	void KeyDeleteDown();
private:
	double modelview[16];
	double projection[16];
	int viewport[4];
private:
	vector<Model> models;
	GLuint TEX_ID;
	VIEW_MODE view_mode = TEX_MODE;

	GLfloat CAM_X;										//图像平移分量
	GLfloat CAM_Z;
	GLfloat CAM_Y;
	GLfloat CAM_TX;										//视图大小，控制缩放
	GLfloat CAM_TY;
	GLfloat CAM_TZ;
	GLfloat CAM_OLDMY, CAM_OLDMX;									//鼠标按下的位置（x,y)
	GLfloat CAM_DELTAX, CAM_DELTAY;									//释放后，x和y移动分量

	objPoint *SELECTED_POINT;
	objPoly *SELECTED_POLY;
	Model *SELECTED_MODEL;
	int MOUSE_BUTTON;
	int WINDOW_HEIGHT;
	int WINDOW_WIDTH;

	const double MIN_SELECTED_PIXEL = 64;
	const double CROSS_PIXEL = 24;

};

#endif // QTGL_H
