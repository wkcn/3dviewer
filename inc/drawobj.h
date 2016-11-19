#ifndef _DRAW_OBJ_H_
#define _DRAW_OBJ_H_

#include <GL/glut.h>
#include <GL/glu.h>
#include "loadobj.h"
#include <vector>
using namespace std;

void DrawObj(const vector<objTriangle> &vt);
void DrawObjPoint(const objPoint &p);

#endif
