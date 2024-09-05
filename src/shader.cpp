#include "shader.h"
#include "log.h"
#include <fstream>
#include <sstream>
#include <iostream>

extern Logger logger;  // Use the global logger instance

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    // Read vertex and fragment shader files
    std::string vertexCode, fragmentCode;
    std::ifstream vShaderFile(vertexPath), fShaderFile(fragmentPath);
    
    if (!vShaderFile || !fShaderFile) {
        logger.log(LogLevel::ERROR, "Failed to read shader files");
    }

    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // Compile shaders
    GLuint vertex = compileShader(vShaderCode, GL_VERTEX_SHADER);
    GLuint fragment = compileShader(fShaderCode, GL_FRAGMENT_SHADER);

    // Link shaders
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    // Check linking errors
    checkCompileErrors(ID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    logger.log(LogLevel::INFO, "Shaders loaded and compiled successfully.");
}

void Shader::use() const {
    glUseProgram(ID);
}

GLuint Shader::compileShader(const char* code, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);
    checkCompileErrors(shader, "SHADER");
    return shader;
}

void Shader::checkCompileErrors(GLuint shader, const std::string& type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            logger.log(LogLevel::ERROR, "Shader compilation error: " + std::string(infoLog));
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            logger.log(LogLevel::ERROR, "Program linking error: " + std::string(infoLog));
        }
    }
}
