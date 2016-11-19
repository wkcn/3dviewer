#include"loadobj.h"

objPoint::objPoint(const glm::vec3& _coordinateVector, const glm::vec2& _textureVector, const glm::vec3& _normalVector)
	: coordinateVector(_coordinateVector), textureVector(_textureVector), normalVector(_normalVector),
	hasTextureVector(true), hasNormalVector(true) {}
objPoint::objPoint(const glm::vec3&_coordinateVector)
	: coordinateVector(_coordinateVector), textureVector(NULL), normalVector(NULL),
	hasTextureVector(false), hasNormalVector(false) {}
objPoint::objPoint(const glm::vec3&_coordinateVector, const glm::vec2&_textureVector)
	: coordinateVector(_coordinateVector), textureVector(_textureVector), normalVector(NULL),
	hasTextureVector(true), hasNormalVector(false) {}
objPoint::objPoint(const glm::vec3&_coordinateVector, const glm::vec3&_normalVector):
	coordinateVector(_coordinateVector), textureVector(NULL), normalVector(_normalVector),
	hasTextureVector(false), hasNormalVector(true) {}
bool objPoint::isTextureVector() const{
	return hasTextureVector;
}

bool objPoint::isNormalVector() const{
	return hasNormalVector;
}

glm::vec3 objPoint::getCoordinateVector() const {
	return coordinateVector;
}

glm::vec2 objPoint::getTextureVector() const {
	return textureVector;
}

glm::vec3 objPoint::getNormalVector() const {
	return normalVector;
}

objTriangle::objTriangle(const objPoint& _p1, const objPoint& _p2, const objPoint& _p3) :
firstPoint(_p1),secondPoint(_p2),thirdPoint(_p3){}

objPoint objTriangle::getFirstPoint() const {
	return firstPoint;
}
objPoint objTriangle::getSecondPoint() const {
	return secondPoint;
}
objPoint objTriangle::getThirdPoint() const {
	return thirdPoint;
}

#include <iostream>
using namespace std;

objPoint GetVSTN(std::ifstream &file, std::vector<glm::vec3> &vs, std::vector<glm::vec2> &vt, std::vector<glm::vec3> &vn){
	std::string s;
	file >> s;
	int par[3];
	int p = 0;
	std::string buf;
	for (char c:s){
		if (c == ' ')continue;
		if (c == '/'){
			if (buf.empty()){
				par[p++] = -1;
			}else{
				int t;
				sscanf(buf.c_str(), "%d", &t);
				par[p++] = t;
			}
			buf.clear();
		}else{
			buf += c;
		}
	}
	int t;
	sscanf(buf.c_str(), "%d", &t);
	par[p++] = t;

	glm::vec3 cv;
	glm::vec2 tv;
	glm::vec3 nv;
	cout << "===" << p << endl;
	cout << par[0] << ", " << par[1] << ", " << par[2] << endl;
	if (par[0] != -1)cv = vs[par[0] - 1];
	if (par[1] != -1)tv = vt[par[1] - 1];
	if (par[2] != -1)nv = vn[par[2] - 1];
	return objPoint(cv,tv,nv);
}

std::vector<objTriangle> loadObj(std::string _filename) {
	std::ifstream file(_filename);
	std::string operatorCh;
	char tempCh;
	std::vector<glm::vec3> vs;
	std::vector<glm::vec3> vn;
	std::vector<glm::vec2> vt;
	std::vector<objTriangle> result;
	double x, y, z;
	double u, v;
	int vs1, vn1, vt1, vs2, vn2, vt2, vs3, vn3, vt3;
	while (!file.eof()) {
		file >> operatorCh;
		if (file.eof())break;
		if (operatorCh == "v") {
			file >> x >> y >> z;
			vs.push_back(glm::vec3(x, y, z));
		}
		if (operatorCh == "vn") {
			file >> x >> y >> z;
			vn.push_back(glm::vec3(x, y, z));
		}
		if (operatorCh == "vt") {
			file >> u >> v;
			vt.push_back(glm::vec2(u, v));
		}
		if (operatorCh == "f") {
			// s/t/n
			objPoint point1 = GetVSTN(file, vs, vt, vn);
			objPoint point2 = GetVSTN(file, vs, vt, vn);
			objPoint point3 = GetVSTN(file, vs, vt, vn);
			objPoint point4 = GetVSTN(file, vs, vt, vn);
			result.push_back(objTriangle(point1, point2, point3));
		}
		if (operatorCh != "v" && operatorCh != "vn" && operatorCh != "vt" && operatorCh != "f")
			std::getline(file, operatorCh);
	}
	return result;
}

