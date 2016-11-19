#include "drawobj.h"
#include <iostream>
using namespace std;

void DrawModel(const Model &md){
	glBegin(GL_TRIANGLES);
	for (const objTriangle &t : md.ts){
		for (int i = 0; i < 3;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();
	glBegin(GL_QUADS);
	for (const objRect &t : md.rs){
		for (int i = 0; i < 4;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();
	glBegin(GL_LINES);
	for (const objLine &t : md.ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
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
