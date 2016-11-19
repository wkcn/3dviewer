#include "objshape.h"

objPoint::objPoint(){}

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

objTriangle::objTriangle(){}

objTriangle::objTriangle(const objPoint& _p1, const objPoint& _p2, const objPoint& _p3){
	points[0] = _p1;
	points[1] = _p2;
	points[2] = _p3;
}

objRect::objRect(){};

objRect::objRect(const objPoint& _p1, const objPoint& _p2, const objPoint& _p3, const objPoint& _p4){
	points[0] = _p1;
	points[1] = _p2;
	points[2] = _p3;
	points[3] = _p4;
}	

objLine::objLine(){};

objLine::objLine(const objPoint& _p1, const objPoint& _p2){
	points[0] = _p1;
	points[1] = _p2;
}	

