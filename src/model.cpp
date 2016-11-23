#include "model.h"

void Model::Draw(){
	glColor4ub(156, 156, 170, 255);
	/*
	glBegin(GL_TRIANGLES);
	for (const objTriangle &t : ts){
		for (int i = 0; i < 3;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (const objRect &t : rs){
		for (int i = 0; i < 4;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();

	*/
	glBegin(GL_LINES);
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();

	for (const objPoly &t : ps){
		glBegin(GL_POLYGON);
		for (const objPoint &p : t.points){
			DrawObjPoint(p);
		}
		glEnd();
	}
}


void Model::DrawLines(){
	/*
	for (const objTriangle &t : ts){
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 3;++i)
				DrawObjPoint(t.points[i]);
		glEnd();
	}

	for (const objRect &t : rs){
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 4;++i)
			DrawObjPoint(t.points[i]);
		glEnd();
	}

	*/
	glBegin(GL_LINES);
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();

	for (const objPoly &t : ps){
		glBegin(GL_LINE_LOOP);
		for (const objPoint &p : t.points){
			DrawObjPoint(p);
		}
		glEnd();
	}
}


void Model::DrawObjPoint(const objPoint &p){
	//cout << cv.x << "-" << cv.y << "-" << cv.z << endl;
	if (p.isTextureVector()){
		glm::vec2 tv = p.getTextureVector();
		glTexCoord2f(tv.x, tv.y);
	}
	if (p.isNormalVector()){
		glm::vec3 nv = p.getNormalVector();
		glNormal3f(nv.x, nv.y, nv.z);
	}
	glm::vec3 cv = p.getCoordinateVector();
	glVertex3f(cv.x, cv.y, cv.z);
}
