#ifndef OBJLOAD_H
#define OBJLOAD_H
#include <iostream>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <string>

class objPoint {
private:
	// Coordinate vector of a point in (x, y, z)
	glm::vec3 coordinateVector;
	// Texture vector of a point in (u, v)
	glm::vec2 textureVector;
	// Normal vector of a point in (x, y, z)
	glm::vec3 normalVector;
public:
	objPoint(const glm::vec3&, const glm::vec2&, const glm::vec3&);
	objPoint(const glm::vec3&);
	objPoint(const glm::vec3&, const glm::vec2&);
	objPoint(const glm::vec3&, const glm::vec3&);
	// Return whether the point has texture vector information or not
	bool isTextureVector();
	// Return whether the point has normal vector information or not
	bool isNormalVector();
	// Return CoordinateVector
	glm::vec3 getCoordinateVector() const;
	// Return TextureVector, please first use isTextureVector()
	// to check if TextureVector exists.
	glm::vec2 getTextureVector() const;
	// Return TextureVector, please first use isNormalVector()
	// to check if NormalVector exists.
	glm::vec3 getNormalVector() const;
};

class objTriangle {
private:
	// Points are connected to each other
	// in order first->second->third->first to form a triangle
	objPoint firstPoint;
	objPoint SecondPoint;
	objPoint ThirdPoint;
public:
	objTriangle(const objPoint&, const objPoint&, const objPoint&) ;
	objPoint getFirstPoint() const;
    objPoint getSecondPoint() const;
    objPoint getThirdPoint() const;
}
// Load a vector of triangles from obj file
std::vector<objTriangle> loadObj(std::string);
#endif
