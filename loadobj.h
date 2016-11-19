#ifndef OBJLOAD_H
#define OBJLOAD_H
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <fstream>
#include <string>
class objPoint {
private:
	// Coordinate vector of a point in (x, y, z)
	glm::vec3 coordinateVector;
	// Texture vector of a point in (u, v)
	glm::vec2 textureVector;
	// Normal vector of a point in (x, y, z)
	glm::vec3 normalVector;
	bool hasTextureVector;
	bool hasNormalVector;
public:
	objPoint(const glm::vec3&, const glm::vec2&, const glm::vec3&);
	objPoint(const glm::vec3&);
	objPoint(const glm::vec3&, const glm::vec2&);
	objPoint(const glm::vec3&, const glm::vec3&);
	// Return whether the point has texture vector information or not
	bool isTextureVector() const;
	// Return whether the point has normal vector information or not
	bool isNormalVector() const;
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
	objPoint secondPoint;
	objPoint thirdPoint;
public:
	objTriangle(const objPoint&, const objPoint&, const objPoint&) ;
	objPoint getFirstPoint() const;
    objPoint getSecondPoint() const;
    objPoint getThirdPoint() const;
};
// Load a vector of triangles from obj file
// The second parameter tells if the obj file has texture and normal vector information
// the default setting is false.
// If it set to true, means it has such informations, which is (v, vt, vn)
// otherwise it is (v)
std::vector<objTriangle> loadObj(const std::string, bool);
#endif
