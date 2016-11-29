
#include "objshape.h"


objPoint::objPoint(int _id, int _tid, int _nid){
    id = _id;
    tid = _tid;
    nid = _nid;
}

bool objPoint::isTextureVector() const{
    return tid;
}

bool objPoint::isNormalVector() const{
	return nid;
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

void objPoly::add(const objPoint &o){
	points.push_back(o);
}
