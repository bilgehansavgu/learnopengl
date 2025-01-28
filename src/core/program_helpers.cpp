#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "program_helpers.h"

OpenGLInitResult initializeOpenGL(OpenGLInitPayload payload)
{
    OpenGLInitResult result;
    result.code = 0;
    result.window = nullptr;

    // glfw: initialize and configure
    // ------------------------------
    if (!glfwInit()) {
        result.code = -1;
        return result;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // glfw: window creation
    // --------------------
    result.window = glfwCreateWindow(payload.SCR_WIDTH, payload.SCR_HEIGHT, payload.window_name.c_str(), NULL, NULL);

    if (!result.window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        result.code = -1;
        return result;
    }

    // glfw: setting context
    // --------------------
    glfwMakeContextCurrent(result.window);

    // glfw: binding callbacks
    // --------------------
    glfwSetKeyCallback(result.window, payload.key_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        result.code = -1;
        return result;
    }

    return result;
}