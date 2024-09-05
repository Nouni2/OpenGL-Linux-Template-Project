#include "renderer.h"
#include "shader.h"
#include "log.h"
#include <GL/glew.h>

extern Logger logger;

Renderer::Renderer() {
    glEnable(GL_DEPTH_TEST);

    // Load shaders
    shader = new Shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    logger.log(LogLevel::INFO, "Renderer initialized.");
}

Renderer::~Renderer() {
    delete shader;
}

void Renderer::render() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use shaders and render objects here
    shader->use();

    // Drawing logic will go here (e.g., sphere rendering)

    // Unbind shaders after use
    glUseProgram(0);
}
