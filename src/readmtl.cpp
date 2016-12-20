#include "readmtl.h"

void read_mtl(string filename, map<string, MTL> &mtls){
	ifstream fin(filename.c_str());
	if (fin.fail()){
		cout << "Not Found " << filename << endl;
		return;
	}
	string buf;
	string tmp;
	MTL mtl;
    mtl.Ka[3] = mtl.Kd[3] = mtl.Ks[3] = 1.0f;
    for (int i = 0; i < 3;++i){
        mtl.Ka[i] = mtl.Kd[i] = mtl.Ks[i] = 1.0f;
    }
	string mtl_name;
	getline(fin, buf);
	while (!fin.eof()){
		stringstream ss(buf);
        buf.clear();
		ss >> tmp;
		if (tmp == "newmtl"){
			if (!mtl_name.empty()){
				mtls[mtl_name] = mtl;

                for (int i = 0; i < 3;++i){
                    mtl.Ka[i] = mtl.Kd[i] = mtl.Ks[i] = 1.0f;
                }
            }
			ss >> mtl_name;
		}else if (tmp == "map_Ka"){
			ss >> mtl.map_Ka;
            for (size_t i = 0;i < mtl.map_Ka.size();++i){
				if (mtl.map_Ka[i] == '\\')mtl.map_Ka[i] = '/';
			}
        }else if (tmp == "Kd"){
            ss >> mtl.Kd[0] >> mtl.Kd[1] >> mtl.Kd[2];
        }else if (tmp == "Ka"){
            ss >> mtl.Ka[0] >> mtl.Ka[1] >> mtl.Ka[2];
        }else if (tmp == "Ks"){
            ss >> mtl.Ks[0] >> mtl.Ks[1] >> mtl.Ks[2];
        }
        getline(fin, buf);
	}
	if (!mtl_name.empty()){
		mtls[mtl_name] = mtl;
	}
	cout << "Read MTL file " << filename << " Success ! " << endl;
}
