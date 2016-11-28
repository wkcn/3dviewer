#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <GL/glut.h>
#include <GL/glu.h>
#include <string>
using namespace std;


GLuint LoadTexture(const string filename);
void DrawAxis();
void DrawGround();

#endif
