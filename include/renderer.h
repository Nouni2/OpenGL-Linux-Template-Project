#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void render() const;

private:
    Shader* shader;
};

#endif // RENDERER_H
