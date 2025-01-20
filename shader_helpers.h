#include <iostream>
#include <glad/glad.h>

#include "shader_io.h"

/**
 * @brief Compiles a shader from a given file path.
 *
 * This function reads the shader source code from the specified file path,
 * compiles it, and returns the shader ID. If the compilation fails, an error
 * message is printed to the standard output.
 *
 * @param shaderPath The file path to the shader source code.
 * @param shaderType The type of the shader (e.g., GL_VERTEX_SHADER, GL_FRAGMENT_SHADER).
 * @return The ID of the compiled shader.
 */
unsigned int compileShader(const std::string &shaderPath, GLenum shaderType);

/**
 * @brief Compiles a shader program from the given vertex and fragment shader IDs.
 *
 * This function creates a shader program, attaches the vertex and fragment shaders
 * to it, links the program, and returns the program ID. If the linking fails, an
 * error message is printed to the standard output.
 *
 * @param vertexShaderID The ID of the vertex shader.
 * @param fragShaderID The ID of the fragment shader.
 * @return The ID of the compiled shader program.
 */
unsigned int compileProgram(unsigned int vertexShaderID, unsigned int fragShaderID);