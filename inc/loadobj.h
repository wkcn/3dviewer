#ifndef OBJLOAD_H
#define OBJLOAD_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "model.h"

// Load a vector of triangles from obj file
// The second parameter tells if the obj file has texture and normal vector information
// the default setting is false.
// If it set to true, means it has such informations, which is (v, vt, vn)
// otherwise it is (v)
Model loadObj(const std::string);
#endif
