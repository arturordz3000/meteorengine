#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int terminateApplication(int resultCode) {
    glfwTerminate();
    return resultCode;
}

int terminateApplication(int resultCode, const std::string& error) {
    std::cerr << error << std::endl;
    return terminateApplication(resultCode);
}

void updateBufferSize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    if (!glfwInit()) {
        return terminateApplication(-1, "Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My OpenGL Test Application", nullptr, nullptr);
    if (!window) {
        return terminateApplication(-1, "Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        return terminateApplication(-1, "Failed to initialize GLEW");
    }

    updateBufferSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, updateBufferSize);

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return terminateApplication(0);
}