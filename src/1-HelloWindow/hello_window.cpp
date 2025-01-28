// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>

// #include "program_helpers.h"


// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
// void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// float vertices[] = {
//     -0.5f, -0.5f, 0.0f,
//      0.5f, -0.5f, 0.0f,
//      0.0f,  0.5f, 0.0f
// };

// // settings
// constexpr unsigned int SCR_WIDTH = 800;
// constexpr unsigned int SCR_HEIGHT = 600;

// int main(void)
// {
//     OpenGLInitPayload payload = {SCR_WIDTH, SCR_HEIGHT, "Hello OpenGL!", key_callback};
//     OpenGLInitResult openGLInstance = initializeOpenGL(payload);

//     unsigned int VBO;
//     glGenBuffers(1, &VBO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glClearColor(0.2f, 0.3f, 0.4f, 1.0f);


//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(openGLInstance.window))
//     {
//         glClear(GL_COLOR_BUFFER_BIT);

//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(openGLInstance.window);
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }