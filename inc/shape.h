#ifndef _SHAPE_H_
#define _SHAPE_H_


#ifndef OS_LINUX
#include <Windows.h>
#pragma execution_character_set("utf-8")
#endif
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <iostream>
#include <string>
#include <cmath>
#include "model.h"
using namespace std;


const double PI = acos(-1);
GLuint LoadTexture(const string filename);
void DrawAxis();
void DrawGround();
Model GetCube(double x, double y, double z);
Model GetCone(double r, double h, int n);
Model GetLoudou(double r, int cn, int hn);
Model GetBall(double r, int cn, int hn);
Model GetPodetium(double r, double h, int n);
#endif
