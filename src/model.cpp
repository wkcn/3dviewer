#include "model.h"
#include "shape.h"

int Model::MODEL_ID = 1;
map<string, int> Model::STR2TEX;

Model::Model():mat(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1){
    name = "undefined";
    id = Model::MODEL_ID++;
    viewed = true;
}	

void Model::BindTexture(){
    if (!tex_name.empty()){
        if (!Model::STR2TEX.count(tex_name)){
            Model::STR2TEX[tex_name] = LoadTexture(tex_name);
        }
        glBindTexture(GL_TEXTURE_2D, Model::STR2TEX[tex_name]);
    }else{
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

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

glm::vec3& Model::GetVertex(int id){
    return vs[id - 1];
}
glm::vec3 Model::GetVertexReal(int id){
	glm::vec3 &ov = vs[id - 1];
	glm::vec4 cv = mat * glm::vec4(ov.x, ov.y, ov.z, 1);	
	return glm::vec3(cv.x, cv.y, cv.z);
}
glm::vec3& Model::GetVN(int id){return vn[id - 1];}
glm::vec2& Model::GetVT(int id){return vt[id - 1];}

void Model::SetVertexPos(int id, double x, double y, double z){
	glm::mat4 mati = glm::inverse(mat);
	glm::vec4 v(x, y, z, 1);
	glm::vec4 t = mati * v;
	vs[id - 1] = glm::vec3(t.x, t.y, t.z); 
}

void Model::DrawLines(){
	glLineWidth(1);
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

#include <iostream>
using namespace std;
void Model::DrawObjPoint(const objPoint &p){
    if (p.isTextureVector()){
        glm::vec2 tv = GetVT(p.tid);
        glTexCoord2f(tv.x, tv.y);
	}
    if (p.isNormalVector()){
		glm::vec3 nv = GetVN(p.nid); 
		glNormal3f(nv.x, nv.y, nv.z);
	}
    glm::vec3 ov = GetVertex(p.id); //p.getCoordinateVector()
    glm::vec4 cv = mat * glm::vec4(ov.x, ov.y, ov.z, 1);
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

void Model::Save(const string filename){
	ofstream fout(filename.c_str());
	for (glm::vec3 &v : vs){
		fout << "v " << v.x << ' ' << v.y << ' ' << v.z << endl;
	}
	fout << "# " << vs.size() << "vertices" << endl;

	for (glm::vec2 &v : vt){
		fout << "vt " << v.x << ' ' << v.y << endl;
	}
	fout << "# " << vt.size() << "texture vertices" << endl;
 
	for (glm::vec3 &v : vn){
		fout << "vn " << v.x << ' ' << v.y << ' ' << v.z << endl;
	}
	fout << "# " << vs.size() << "vertices normals" << endl;
	for (objPoly &p : ps){
		fout << "f ";
		for (objPoint &o : p.points){
			fout << o.id;
			if (o.tid || o.nid){
				fout << '/';
				if (o.tid)fout << o.tid;
				fout << '/';
				if (o.nid)fout << o.nid;
			}
			fout << ' ';
		}
		fout << endl;
	}
	fout.close();
}

void Model::MatMapVertices(){
	for (int i = 1;i <= vs.size();++i){
		vs[i - 1] = GetVertexReal(i);
	}
	mat = glm::mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
}
