#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;

private:
    GLuint ID;
    GLuint compileShader(const char* code, GLenum type);
    void checkCompileErrors(GLuint shader, const std::string& type);
};

#endif // SHADER_H
