#include <iostream>
#include <glad/glad.h>

#include "shader_io.h"

unsigned int compileShader(const std::string &shaderPath, GLenum shaderType)
{
    unsigned int shaderID;
    shaderID = glCreateShader(shaderType);
    std::string shaderString = LoadShaderAsString(shaderPath);
    const char* shaderSource = shaderString.c_str();
    glShaderSource(shaderID, 1, &shaderSource, NULL);
    glCompileShader(shaderID);
    
    int compileSuccess;
    char compileInfoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileSuccess);
    if (!compileSuccess)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, compileInfoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << compileInfoLog << std::endl;
    }
    return shaderID;
}

unsigned int compileProgram(unsigned int vertexShaderID, unsigned int fragShaderID)
{
    unsigned int shaderProgramID;
    shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vertexShaderID);
    glAttachShader(shaderProgramID, fragShaderID);
    glLinkProgram(shaderProgramID);
    
    int linkSuccess;
    char linkInfoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess)
    {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, linkInfoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << linkInfoLog << std::endl;
    }
}