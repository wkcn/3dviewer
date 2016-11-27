#ifndef _GLUT_THREAD_H_
#define _GLUT_THREAD_H_
#include <QThread>
#include <QSemaphore>
#include <GL/glut.h>
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

class GLUT_Thread : public QThread{
	Q_OBJECT
public:
	GLUT_Thread();
	void run();
public:
	void SetViewMode(VIEW_MODE mode);
private:
};

#endif
