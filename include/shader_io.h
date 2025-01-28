#ifndef SHADER_IO_H
#define SHADER_IO_H

#include <iostream>

bool LoadShaderAsString(std::string &shaderSource, const std::string &filename);
std::string getResourcePath(const std::string& relativePath);

#endif