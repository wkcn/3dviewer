#ifndef _READMTL_H_
#define _READMTL_H_
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <glm/vec3.hpp>
using namespace std;

struct MTL{
	string map_Ka;
    float Ka[4], Kd[4], Ks[4];
};

void read_mtl(string filename, map<string, MTL> &mtls);

#endif
