#ifndef _MODEL_H_
#define _MODEL_H_

#include <GL/glut.h>
#include <GL/glu.h>
#include "objshape.h"

class Model{
	public:
		void Draw();
	public:
		std::vector<objTriangle> ts;
		std::vector<objRect> rs;
		std::vector<objLine> ls;
		std::vector<objPoly> ps;
	private:
		void DrawObjPoint(const objPoint &p);
};

#endif
