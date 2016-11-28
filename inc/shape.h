#ifndef _SHAPE_H_
#define _SHAPE_H_


#include <Windows.h>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>

#include <iostream>
#include <string>
#include "model.h"
using namespace std;


GLuint LoadTexture(const string filename);
void DrawAxis();
void DrawGround();
Model GetCube(double x, double y, double z);

#endif
