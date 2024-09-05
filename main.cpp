#include "window.h"
#include "renderer.h"
#include "log.h"

extern Logger logger;

int main() {
    // Set log level (optional, can set to DEBUG, INFO, etc.)
    logger.setLogLevel(LogLevel::DEBUG);

    // Log application start
    logger.log(LogLevel::INFO, "Application started.");

    // Create window
    Window window(800, 600, "ShaderLab");

    // Initialize renderer
    Renderer renderer;

    // Main loop
    while (!window.shouldClose()) {
        window.pollEvents();
        renderer.render();
        window.swapBuffers();
    }

    // Log application termination
    logger.log(LogLevel::INFO, "Application terminated.");
    return 0;
}
