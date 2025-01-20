#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "program_helpers.h"
#include "shader_io.h"
#include "shader_helpers.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices1[] = {
    -0.2f, -0.2f, 0.0f,
    0.1f, -0.1f, 0.0f,
    0.0f,  0.1f, 0.0f,
};

float vertices2[] = {
    0.3f, 0.1f, 0.0f,
    0.3f, -0.1f, 0.0f,
    0.2f,  0.1f, 0.0f,
};

int main()
{
    OpenGLInitPayload payload = {SCR_WIDTH, SCR_HEIGHT, "Hello OpenGL!", key_callback};
    OpenGLInitResult openGLInstance = initializeOpenGL(payload);

    unsigned int VAOs[2], VBOs[2];

    glGenVertexArrays(2, VAOs);
    glBindVertexArray(VAOs[0]);

    glGenBuffers(2, VBOs);

    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    unsigned int vertexShaderID;
    vertexShaderID = compileShader("shaders/vertex.glsl", GL_VERTEX_SHADER);

    unsigned int fragShaderID;
    fragShaderID = compileShader("shaders/frag.glsl", GL_FRAGMENT_SHADER);

    unsigned int ProgramID;
    ProgramID = compileProgram(vertexShaderID, fragShaderID);

    unsigned int fragShader1ID;
    compileShader("shaders/frag1.glsl", GL_FRAGMENT_SHADER);

    unsigned int compileProgram(unsigned int vertexShaderID, unsigned int fragShader1ID);

    unsigned int shaderProgram1ID;
    shaderProgram1ID = compileProgram(vertexShaderID, fragShader1ID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragShaderID);

    while (!glfwWindowShouldClose(openGLInstance.window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(ProgramID);

        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram1ID);

        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(openGLInstance.window);
        glfwPollEvents();
    }

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    glfwTerminate();
    return 0;
    
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}