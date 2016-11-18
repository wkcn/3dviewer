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
	objPoint(glm::vec3, glm::vec2, glm::vec3);
	objPoint(glm::vec3);
	objPoint(glm::vec3, glm::vec2);
	objPoint(glm::vec3, glm::vec3);
	// Return whether the point has texture vector information
	bool isTextureVector();
	// Return whether the point has normal vector information
	bool isNormalVector();
};
// Load a vector of points from obj file
std::vector<objPoint> loadObj(std::string);
#endif
