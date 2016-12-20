#include "readmtl.h"

void read_mtl(string filename, map<string, MTL> &mtls){
	ifstream fin(filename.c_str());
	if (fin.fail()){
		cout << "Not Found " << filename << endl;
		return;
	}
	string mtlname;
	string buf;
	string tmp;
	MTL mtl;
	string mtl_name;
	getline(fin, buf);
	while (!fin.eof()){
		stringstream ss(buf);
		ss >> tmp;
		if (tmp == "newmtl"){
			if (!mtl_name.empty()){
				mtls[mtl_name] = mtl;
			}
			ss >> mtl_name;
		}else if (tmp == "map_Ka"){
			ss >> mtl.map_Ka;
			for (int i = 0;i < mtl.map_Ka.size();++i){
				if (mtl.map_Ka[i] == '\\')mtl.map_Ka[i] = '/';
			}
		}
		getline(fin, buf);
	}
	if (!mtl_name.empty()){
		mtls[mtl_name] = mtl;
	}
	cout << "Read MTL file " << filename << " Success ! " << endl;
}
