#ifndef _DRAW_OBJ_H_
#define _DRAW_OBJ_H_

#include <GL/glut.h>
#include <GL/glu.h>
#include "loadobj.h"
#include <vector>
using namespace std;

void DrawModel(const Model &);
void DrawObjPoint(const objPoint &p);

#endif
