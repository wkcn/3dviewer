#ifndef _SHAPE_H_
#define _SHAPE_H_


#ifdef Q_OS_WIN32
#include <Windows.h>
#endif
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <iostream>
#include <string>
#include "model.h"
using namespace std;


GLuint LoadTexture(const string filename);
void DrawAxis();
void DrawGround();
Model GetCube(double x, double y, double z);

#endif
