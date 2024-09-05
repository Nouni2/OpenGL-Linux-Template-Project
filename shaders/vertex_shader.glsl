#version 330 core

// Vertex shader input: position attribute
layout(location = 0) in vec3 aPos;

// Output to the fragment shader
void main() {
    // Set the vertex position, converting it to 4D
    gl_Position = vec4(aPos, 1.0);
}
