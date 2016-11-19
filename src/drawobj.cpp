#include "drawobj.h"
#include <iostream>
using namespace std;

void DrawObj(const vector<objTriangle> &vt){
	glBegin(GL_TRIANGLES);
	for (const objTriangle &t : vt){
		objPoint p0 = t.getFirstPoint();
		objPoint p1 = t.getSecondPoint();
		objPoint p2 = t.getThirdPoint();
		DrawObjPoint(p0);
		DrawObjPoint(p1);
		DrawObjPoint(p2);
	}
	glEnd();
}

void DrawObjPoint(const objPoint &p){
	glm::vec3 cv = p.getCoordinateVector();
	glVertex3f(cv.x, cv.y, cv.z);
	//cout << cv.x << "-" << cv.y << "-" << cv.z << endl;
	if (p.isTextureVector()){
		glm::vec2 tv = p.getTextureVector();
		glTexCoord2f(tv.x, tv.y);
	}
	if (p.isNormalVector()){
		glm::vec3 nv = p.getNormalVector();
		glNormal3f(nv.x, nv.y, nv.z);
	}
}
