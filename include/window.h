#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>   // GLEW must be included before any OpenGL headers
#include <GLFW/glfw3.h> // GLFW headers

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();
    
    void pollEvents() const;
    void swapBuffers() const;
    bool shouldClose() const;

private:
    GLFWwindow* window;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif // WINDOW_H
