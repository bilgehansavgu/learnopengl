#include "shader_helpers.h"

bool compileShader(unsigned int &shaderID, const std::string &shaderPath, GLenum shaderType)
{
    shaderID = glCreateShader(shaderType);
    std::string shaderString;
    if(!LoadShaderAsString(shaderString, shaderPath)){
        return false;
    }

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
        return false;
    }

    return true;
}

bool compileProgram(unsigned int &shaderProgramID, unsigned int vertexShaderID, unsigned int fragShaderID)
{
    shaderProgramID = glCreateProgram();
    
    glAttachShader(shaderProgramID, vertexShaderID);
    glAttachShader(shaderProgramID, fragShaderID);
    glLinkProgram(shaderProgramID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragShaderID);
    
    int linkSuccess;
    char linkInfoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess)
    {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, linkInfoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << linkInfoLog << std::endl;

        return false;
    }
    
    return true;
}