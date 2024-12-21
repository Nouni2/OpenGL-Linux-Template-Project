#ifndef IGUI_H
#define IGUI_H

#include <GLFW/glfw3.h>
#include "log.h"

class IGui {
public:
    IGui(GLFWwindow* window);   // Constructor
    ~IGui();                   // Destructor

    void beginFrame();         // Start a new ImGui frame
    void endFrame();           // Render the ImGui frame
    void render();             // Render UI during the frame

private:
    void initialize(GLFWwindow* window); // Initialize ImGui
    void cleanup();                      // Cleanup ImGui
};

#endif // IGUI_H
