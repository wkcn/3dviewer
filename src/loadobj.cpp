
#include "loadobj.h"

objPoint GetVSTN(std::string &s){
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

	return objPoint(par[0],par[1],par[2]);
}

Model loadObj(std::string _filename) {
	int end_i = _filename.size() - 1;
	for (;end_i >= 0;--end_i){
		char c = _filename[end_i];
		if (c == '\\' || c == '/')break;
	}
	if (end_i < 0)end_i = _filename.size() - 1; 
	std::string path = _filename.substr(0, end_i + 1); 
	cout << "Load Obj " << _filename << endl;
	std::ifstream file(_filename);
	if (file.fail()){
		std::cout << "Read " << _filename << " Error :-(" << std::endl;
		return Model();
	}
	std::string operatorCh;
	Model md;
	md.path = path;
	std::vector<glm::vec3> &vs = md.vs;
	std::vector<glm::vec3> &vn = md.vn;
	std::vector<glm::vec2> &vt = md.vt;
	std::vector<objPoly> triangles;
	std::vector<objPoly> rects;
	std::vector<objPoly> others;
	double x, y, z;
	double u, v;
	string mtl_name;
	while (!file.eof()) {
		file >> operatorCh;
		if (file.eof())break;
		if (operatorCh == "v") {
			file >> x >> y >> z;
			vs.push_back(glm::vec3(x, y, z));
		}else if (operatorCh == "vn") {
			file >> x >> y >> z;
			vn.push_back(glm::vec3(x, y, z));
		}else if (operatorCh == "vt") {
			file >> u >> v;
			vt.push_back(glm::vec2(u, v));
		}else if (operatorCh == "f") {
			// s/t/n
			std::string buf;
			std::getline(file, buf);
			std::stringstream ss;
			ss << buf;
			objPoly op;
			while (!ss.eof()){
                std::string buf;
                ss >> buf;
                if (buf.size()){
                    objPoint p = GetVSTN(buf);
                    op.points.push_back(p);
                }
				op.mtl = mtl_name;
			}
            // Check
            bool err = false;
            for (objPoint &p : op.points){
                if (p.id > vs.size() || p.tid > vt.size() || p.nid > vn.size()){
                    err = true;
                    cout << "Error: " << p.id << "/" << p.tid << "/" << p.nid;
                    cout << "[" << vs.size() << ", " << vt.size() << ", " << vn.size() << "]" << endl;
                    break;
                }
            }
            if (err)continue;
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
		}else if (operatorCh == "usemtl"){
			file >> mtl_name;
			//cout << mtl_name << endl;
		}else if (operatorCh == "mtllib"){
			string mtllib;
			file >> mtllib;
			read_mtl(path + mtllib, md.mtls);
		}else{	
            std::string h = "\n";
            std::getline(file, h);//operatorCh);
        }
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
	cout << "Load Obj File " << _filename << " Success :-)" << endl;
	return md; 
}

