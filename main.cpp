#include "window.h"
#include "renderer.h"
#include "log.h"
#include "igui.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

extern Logger logger;

int main() {
    // Set minimal log level (optional, can be set to DEBUG, INFO, etc.)
    logger.setLogLevel(LogLevel::DEBUG);

    // Log application start
    logger.log(LogLevel::INFO, "Application started.");

    // Create window
    Window window(800, 600, "ProjectName"); // Change the window title

    // Initialize renderer
    Renderer renderer;

    // Initialize ImGui through the IGui class
    IGui igui(window.getGLFWHandle());

    // Main loop
    while (!window.shouldClose()) {
        // Poll events
        window.pollEvents();

        // Start ImGui frame
        igui.beginFrame();

        // Render ImGui UI
        igui.render();

        // End ImGui frame
        igui.endFrame();

        // Render OpenGL content
        renderer.render();

        // Render ImGui on top of OpenGL content
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        window.swapBuffers();
    }

    // Log application termination
    logger.log(LogLevel::INFO, "Application terminated.");
    return 0;
}
