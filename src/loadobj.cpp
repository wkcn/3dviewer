#include "inc/loadobj.h"

objPoint GetVSTN(std::stringstream &file, std::vector<glm::vec3> &vs, std::vector<glm::vec2> &vt, std::vector<glm::vec3> &vn){
	std::string s;
	file >> s;
	int par[3] = {0,0,0};
	int p = 0;
	std::string buf;
	for (char c:s){
		if (c == ' ')continue;
		if (c == '/'){
			if (buf.empty()){
				par[p++] = 0;
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

	//glm::vec3 cv;
	glm::vec2 tv;
	glm::vec3 nv;
	//if (par[0])cv = vs[par[0] - 1];
	if (par[1])tv = vt[par[1] - 1];
	if (par[2])nv = vn[par[2] - 1];
	return objPoint(par[0] - 1,tv,nv);
}

Model loadObj(std::string _filename) {
	std::ifstream file(_filename);
	if (file.fail()){
		std::cout << "Read " << _filename << " Error :-(" << std::endl;
		return Model();
	}
	std::string operatorCh;
	Model md;
	std::vector<glm::vec3> &vs = md.vs;
	std::vector<glm::vec3> vn;
	std::vector<glm::vec2> vt;
	std::vector<objPoly> triangles;
	std::vector<objPoly> rects;
	std::vector<objPoly> others;
	double x, y, z;
	double u, v;
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
			std::string buf;
			std::getline(file, buf);
			std::stringstream ss;
			ss << buf;
			objPoly op;
			while (!ss.eof()){
				objPoint p = GetVSTN(ss, vs, vt, vn);
				op.points.push_back(p);
			}
			switch(op.points.size()){
			case 3:
				triangles.push_back(op);
				break;
			case 4:
				rects.push_back(op);
				break;
			default:
				others.push_back(op);
			}
		}	
		/*
		if (operatorCh == "l"){
			int a,b;
			file >> a >> b;
			md.ls.push_back(objLine(vs[a-1], vs[b-1]));
		}
		*/
		if (operatorCh != "v" && operatorCh != "vn" && operatorCh != "vt" && operatorCh != "f")
			std::getline(file, operatorCh);
	}

	md.triangleNum = triangles.size();
	md.rectNum = rects.size();
	md.ps.resize(triangles.size() + rects.size() + others.size());
	int k = 0;
	for (objPoly &p : triangles){
		md.ps[k++] = p;
	}
	for (objPoly &p : rects){
		md.ps[k++] = p;
	}
	for (objPoly &p : others){
		md.ps[k++] = p;
	}
	return md; 
}

