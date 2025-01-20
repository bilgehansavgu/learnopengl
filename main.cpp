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
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// int main(void)
// {
//     OpenGLInitPayload payload = {SCR_WIDTH, SCR_HEIGHT, "Hello OpenGL!", key_callback};
//     OpenGLInitResult setup_result = initializeOpenGL(payload);

//     unsigned int VBO;
//     glGenBuffers(1, &VBO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glClearColor(0.2f, 0.3f, 0.4f, 1.0f);


//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(setup_result.window))
//     {
//         glClear(GL_COLOR_BUFFER_BIT);

//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(setup_result.window);
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//         glfwSetWindowShouldClose(window, true);
//     }
// }

// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }