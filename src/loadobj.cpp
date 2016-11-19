#include "loadobj.h"

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

	glm::vec3 cv;
	glm::vec2 tv;
	glm::vec3 nv;
	if (par[0])cv = vs[par[0] - 1];
	if (par[1])tv = vt[par[1] - 1];
	if (par[2])nv = vn[par[2] - 1];
	return objPoint(cv,tv,nv);
}

Model loadObj(std::string _filename) {
	std::ifstream file(_filename);
	std::string operatorCh;
	char tempCh;
	std::vector<glm::vec3> vs;
	std::vector<glm::vec3> vn;
	std::vector<glm::vec2> vt;
	Model result;
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
			std::string buf;
			std::getline(file, buf);
			std::stringstream ss;
			ss << buf;
			objPoint point1 = GetVSTN(ss, vs, vt, vn);
			objPoint point2 = GetVSTN(ss, vs, vt, vn);
			objPoint point3 = GetVSTN(ss, vs, vt, vn);
			if (!ss.eof()){
				objPoint point4 = GetVSTN(ss, vs, vt, vn);
				result.rs.push_back(objRect(point1, point2, point3, point4));
			}else{
				result.ts.push_back(objTriangle(point1, point2, point3));
			} 
		}
		if (operatorCh == "l"){
			int a,b;
			file >> a >> b;
			result.ls.push_back(objLine(vs[a-1], vs[b-1]));
		}
		if (operatorCh != "v" && operatorCh != "vn" && operatorCh != "vt" && operatorCh != "f")
			std::getline(file, operatorCh);
	}
	return result;
}

