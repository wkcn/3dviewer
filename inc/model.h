#ifndef _MODEL_H_
#define _MODEL_H_

#ifndef OS_LINUX
#include <Windows.h>
#include <GL/glut.h>
#pragma execution_character_set("utf-8")
#endif
#include <GL/glu.h>
#include <GL/gl.h>
#include "objshape.h"
#include <string>
#include <fstream>
#include <map>
#include <glm/mat4x4.hpp>
using namespace std;

class Model{
	public:
		Model();
		void Draw();
		void DrawLines();
		void DrawPoints();
		void Rebuild();
		glm::vec3 GetVertexReal(int id);
		glm::vec3& GetVertex(int id);
        glm::vec3 GetVNReal(int id);
		glm::vec3& GetVN(int id);
		glm::vec2& GetVT(int id);
		void SetVertexPos(int id, double x, double y, double z);
		void MatMapVertices();
		void Save(const string filename);
        void BindTexture();
	public:
        int id;
		string name;
        string tex_name;
        bool viewed;
        bool texed;
		std::vector<objPoly> ps; // 多边形集合
		std::vector<glm::vec3> vs; // 顶点集合
		std::vector<glm::vec3> vn; // 法线集合
		std::vector<glm::vec2> vt; // 贴图顶点集合
		glm::mat4 mat; // 内部矩阵
		int triangleNum;
		int rectNum;
    private:
        static int MODEL_ID;
        static map<string, int> STR2TEX;
	private:
		void DrawObjPoint(const objPoint &p);
};

#endif
