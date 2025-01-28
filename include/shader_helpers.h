#ifndef SHADER_HELPERS_H
#define SHADER_HELPERS_H

#include <iostream>
#include <glad/glad.h>

#include "shader_io.h"

bool compileShader(unsigned int &shaderID, const std::string &shaderPath, GLenum shaderType);
bool compileProgram(unsigned int &shaderProgramID, unsigned int vertexShaderID, unsigned int fragShaderID);

#endif