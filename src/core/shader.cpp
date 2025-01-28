#include "shader.h"
#include "shader_io.h"
#include "shader_helpers.h"

Shader::Shader() : ID(0) {}

Shader::~Shader() {
    if (ID != 0) {
        glDeleteProgram(ID);
    }
}

bool Shader::load(const char *vertexPath, const char *fragPath)
{
    unsigned int vertShaderID;
    if(!compileShader(vertShaderID, vertexPath, GL_VERTEX_SHADER)) return false;

    unsigned int fragShaderID;
    if(!compileShader(fragShaderID, fragPath, GL_FRAGMENT_SHADER)) return false;

    unsigned int programID;
    if(!compileProgram(programID, vertShaderID, fragShaderID)) return false;

    ID = programID;
    // std::cout << "Program ID: " << ID << std::endl;

    return true;
}

void Shader::use() const
{
    if (ID != 0) {
        glUseProgram(ID);
    }
}

unsigned int Shader::getID() const
{
    return ID;
}
