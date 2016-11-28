#ifndef _OBJ_SHAPE_H_
#define _OBJ_SHAPE_H_

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

class objPoint {
public:
	int id; // 改用记录顶点ID的方式
	int tid;
	int nid;
	// Coordinate vector of a point in (x, y, z)
	//glm::vec3 coordinateVector;
	// Texture vector of a point in (u, v)
	//glm::vec2 textureVector;
	// Normal vector of a point in (x, y, z)
	//glm::vec3 normalVector;
private:
	//bool hasTextureVector;
	//bool hasNormalVector;
public:
	objPoint(int _id = 0,int _tid = 0,int _nid = 0);
	// Return whether the point has texture vector information or not
	bool isTextureVector() const;
	// Return whether the point has normal vector information or not
	bool isNormalVector() const;
};

class objTriangle {
public:
	// Points are connected to each other
	objPoint points[3];
public:
	objTriangle();
	objTriangle(const objPoint&, const objPoint&, const objPoint&) ;
};


class objRect {
public:
	// Points are connected to each other
	objPoint points[4];
public:
	objRect();
	objRect(const objPoint&, const objPoint&, const objPoint&, const objPoint&) ;
};

class objLine {
public:
	// Points are connected to each other
	objPoint points[2];
public:
	objLine();
	objLine(const objPoint&, const objPoint&) ;
};

class objPoly {
public:
	std::vector<objPoint> points;
public:
	void add(const objPoint &);
};



#endif
