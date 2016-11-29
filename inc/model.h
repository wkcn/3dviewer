#ifndef _MODEL_H_
#define _MODEL_H_

#include <Windows.h>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include "objshape.h"
#include <string>
using namespace std;

class Model{
	public:
		void Draw();
		void DrawLines();
		void DrawPoints();
		void Rebuild();
		glm::vec3& GetVertex(int id);
		glm::vec3& GetVN(int id);
		glm::vec2& GetVT(int id);
	public:
		string name;
		std::vector<objPoly> ps; // 多边形集合
		std::vector<glm::vec3> vs; // 顶点集合
		std::vector<glm::vec3> vn; // 法线集合
		std::vector<glm::vec2> vt; // 贴图顶点集合
		int triangleNum;
		int rectNum;
	private:
		void DrawObjPoint(const objPoint &p);
};

#endif
