#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "program_helpers.h"
#include "shader_io.h"

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
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    std::string vShaderString = LoadShaderAsString("shaders/vertex.glsl");
    const char* vertexShaderSource = vShaderString.c_str();
    glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderID);
    int vertexCompileSuccess;
    char vertexCompileInfoLog[512];
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &vertexCompileSuccess);
    if (!vertexCompileSuccess)
    {
        glGetShaderInfoLog(vertexShaderID, 512, NULL, vertexCompileInfoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vertexCompileInfoLog << std::endl;
    }

    unsigned int fragShaderID;
    fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fShaderString = LoadShaderAsString("shaders/frag.glsl");
    const char* fragShaderSource = fShaderString.c_str();
    glShaderSource(fragShaderID, 1, &fragShaderSource, NULL);
    glCompileShader(fragShaderID);
    int fragCompileSuccess;
    char fragCompileInfoLog[512];
    glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &fragCompileSuccess);
    if (!fragCompileSuccess)
    {
        glGetShaderInfoLog(fragShaderID, 512, NULL, fragCompileInfoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << fragCompileInfoLog << std::endl;
    }

    unsigned int fragShader1ID;
    fragShader1ID = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fShaderString1 = LoadShaderAsString("shaders/frag_1.glsl");
    const char* fragShaderSource1 = fShaderString1.c_str();
    glShaderSource(fragShader1ID, 1, &fragShaderSource1, NULL);
    glCompileShader(fragShader1ID);
    int fragCompileSuccess1;
    char fragCompileInfoLog1[512];
    glGetShaderiv(fragShader1ID, GL_COMPILE_STATUS, &fragCompileSuccess1);
    if (!fragCompileSuccess1)
    {
        glGetShaderInfoLog(fragShader1ID, 512, NULL, fragCompileInfoLog1);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << fragCompileInfoLog1 << std::endl;
    }

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

    unsigned int shaderProgram1ID;
    shaderProgram1ID = glCreateProgram();
    glAttachShader(shaderProgram1ID, vertexShaderID);
    glAttachShader(shaderProgram1ID, fragShader1ID);
    glLinkProgram(shaderProgram1ID);
    int linkSuccess1;
    char linkInfoLog1[512];
    glGetProgramiv(shaderProgram1ID, GL_LINK_STATUS, &linkSuccess1);
    if (!linkSuccess1)
    {
        glGetProgramInfoLog(shaderProgram1ID, 512, NULL, linkInfoLog1);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << linkInfoLog1 << std::endl;
    }

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragShaderID);

    while (!glfwWindowShouldClose(openGLInstance.window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgramID);

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