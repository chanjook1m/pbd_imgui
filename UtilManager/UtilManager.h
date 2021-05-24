#ifndef _UTIL_H
#define _UTIL_H

#pragma once

#include "GL/glew.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <memory>
#include <Eigen/Dense>
#include <Eigen/Sparse>



//#include "Utils/FileSystem.h"
class UtilManager
{
public:
	UtilManager();
	~UtilManager();

public:
	/*static bool loadOBJ_proto(
		const char* path,
		std::vector<Eigen::Vector3f>& out_vertices,
		std::vector<Eigen::Vector2f>& out_uvs,
		std::vector<Eigen::Vector3f>& out_normals
	);*/
	static bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	static GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

};
#endif