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

std::vector<objTriangle> loadObj(std::string _filename, bool _addtional = false) {
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
			if(!_addtional) {
				file >> vs1 >>
					vs2 >>
					vs3;
				objPoint point1(vs[vs1 - 1]);
				objPoint point2(vs[vs2 - 1]);
				objPoint point3(vs[vs3 - 1]);
				result.push_back(objTriangle(point1, point2, point3));

			}
			else {
				file >> vs1 >> tempCh >> vt1 >> tempCh >> vn1 >>
					vs2 >> tempCh >> vt2 >> tempCh >> vn2 >>
					vs3 >> tempCh >> vt3 >> tempCh >> vn3;
				objPoint point1(vs[vs1 - 1], vt[vt1 - 1], vn[vn1 - 1]);
				objPoint point2(vs[vs2 - 1], vt[vt2 - 1], vn[vn2 - 1]);
				objPoint point3(vs[vs3 - 1], vt[vt3 - 1], vn[vn3 - 1]);
				result.push_back(objTriangle(point1, point2, point3));

			}
		}
		if (operatorCh != "v" && operatorCh != "vn" && operatorCh != "vt" && operatorCh != "f")
			std::getline(file, operatorCh);
	}
	return result;
}

