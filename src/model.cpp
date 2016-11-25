#include "model.h"

void Model::Draw(){
	glColor4ub(156, 156, 170, 255);
	glBegin(GL_LINES);
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();

	int k = 0;
	int endk = triangleNum;
	// 绘制三角形
	glBegin(GL_TRIANGLES);
	for (;k < endk;++k){
		objPoly &t = ps[k];
		for (int i = 0; i < 3;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();
	endk += rectNum;
	// 绘制四边形
	glBegin(GL_QUADS);
	for (;k < endk;++k){
		objPoly &t = ps[k];
		for (int i = 0; i < 4;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();
	endk = ps.size();
	for (;k < endk;++k){
		objPoly &t = ps[k];
		glBegin(GL_POLYGON);
		for (const objPoint &p : t.points){
			DrawObjPoint(p);
		}
		glEnd();
	}

}


void Model::DrawLines(){
	glLineWidth(1);
	glColor3ub(255, 0, 0);
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

void Model::DrawPoints(){
	glPointSize(3);
	glColor3ub(255, 0, 0);
	glBegin(GL_POINTS);
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}

	for (const objPoly &t : ps){
		for (const objPoint &p : t.points){
			DrawObjPoint(p);
		}
	}
	glEnd();
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
