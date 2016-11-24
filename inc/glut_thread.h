#ifndef _GLUT_THREAD_H_
#define _GLUT_THREAD_H_
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <string>
#include "loadobj.h"
#include "model.h"
using namespace std;

#include <QThread>
class GLUT_Thread : public QThread{
	Q_OBJECT
public:
	GLUT_Thread();
	void run();

};

#endif
