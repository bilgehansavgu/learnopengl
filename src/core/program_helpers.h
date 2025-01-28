#ifndef PROGRAM_HELPERS_H
#define PROGRAM_HELPERS_H

#include <iostream>
#include <GLFW/glfw3.h>

struct OpenGLInitPayload {
    unsigned int SCR_WIDTH;
    unsigned int SCR_HEIGHT;
    std::string window_name;
    GLFWkeyfun key_callback;

    OpenGLInitPayload(int width, int height, const std::string& name = "Hello World", GLFWkeyfun callback = nullptr)
        : SCR_WIDTH(width), SCR_HEIGHT(height), window_name(name), key_callback(callback) {}
};

struct OpenGLInitResult {
    int code;
    GLFWwindow* window;
};

OpenGLInitResult initializeOpenGL(OpenGLInitPayload payload);

#endif