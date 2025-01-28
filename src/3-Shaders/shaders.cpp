#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "program_helpers.h"
#include "glfw_callbacks.h"
#include "shader_io.h"
#include "shader_helpers.h"
#include "shader.h"

constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};    

int main() {
    OpenGLInitPayload payload = {SCR_WIDTH, SCR_HEIGHT, "Hello OpenGL!", key_callback};
    OpenGLInitResult openGLInstance = initializeOpenGL(payload);



    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO); 

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3* sizeof(float)));
    glEnableVertexAttribArray(1);

    Shader shaderProgram;

    std::string vertPath = getResourcePath("/Users/bilgehansavgu/Documents/OpenGL/projects/LearnOpenGL/src/3-Shaders/shaders_vert.glsl");
    std::string fragPath = getResourcePath("/Users/bilgehansavgu/Documents/OpenGL/projects/LearnOpenGL/src/3-Shaders/shaders_frag.glsl");
    shaderProgram.load(vertPath.c_str(), fragPath.c_str());

    float offsetX = 0.6f;

    while(!glfwWindowShouldClose(openGLInstance.window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // float timeValue = glfwGetTime();
        // float greenValue = sin(timeValue) / 2.0f + 0.5f;

        int offsetLoc = glGetUniformLocation(shaderProgram.getID(), "horizontalOffset");
        glUniform1f(offsetLoc, offsetX);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(openGLInstance.window);
        glfwPollEvents();
    }

    return 0;
}