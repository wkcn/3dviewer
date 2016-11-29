#include "model.h"

void Model::Draw(){
	glColor4ub(156, 156, 170, 255);
	/*
	glBegin(GL_LINES);
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();
	*/

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

glm::vec3& Model::GetVertex(int id){return vs[id - 1];}
glm::vec3& Model::GetVN(int id){return vn[id - 1];}
glm::vec2& Model::GetVT(int id){return vt[id - 1];}

void Model::DrawLines(){
	glLineWidth(1);
	glColor3ub(255, 0, 0);
	/*
	glBegin(GL_LINES);
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}
	glEnd();
	*/

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
	/*
	for (const objLine &t : ls){
		for (int i = 0; i < 2;++i)
			DrawObjPoint(t.points[i]);
	}
	*/

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
		glm::vec2 tv = GetVT(p.tid); 
		glTexCoord2f(tv.x, tv.y);
	}
	if (p.isNormalVector()){
		glm::vec3 nv = GetVN(p.nid); 
		glNormal3f(nv.x, nv.y, nv.z);
	}
	glm::vec3 cv = GetVertex(p.id); //p.getCoordinateVector();
	glVertex3f(cv.x, cv.y, cv.z);
}

void Model::Rebuild(){
	vector<objPoly> triangles;
	vector<objPoly> rects;
	vector<objPoly> others;
	for (objPoly &p:ps){
		if (p.points.size() < 3)continue;
		switch(p.points.size()){
			case 3:
				triangles.push_back(p);
				break;
			case 4:
				rects.push_back(p);
				break;
			default:
				others.push_back(p);
		};
	}
	triangleNum = triangles.size();
	rectNum = rects.size();
	ps.resize(triangles.size() + rects.size() + others.size());
	int k = 0;
	for (objPoly &p : triangles){
		ps[k++] = p;
	}
	for (objPoly &p : rects){
		ps[k++] = p;
	}
	for (objPoly &p : others){
		ps[k++] = p;
	}

}
