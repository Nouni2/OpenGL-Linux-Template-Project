#include "window.h"
#include "log.h"
#include <GLFW/glfw3.h>
#include <GL/glew.h>

extern Logger logger;  // Use the global logger instance

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title) {
    if (!glfwInit()) {
        logger.log(LogLevel::ERROR, "Failed to initialize GLFW");
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        logger.log(LogLevel::ERROR, "Failed to create GLFW window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        logger.log(LogLevel::ERROR, "Failed to initialize GLEW");
    }

    logger.log(LogLevel::INFO, "Window created successfully.");
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::pollEvents() const {
    glfwPollEvents();
}

void Window::swapBuffers() const {
    glfwSwapBuffers(window);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}
