#include "Triangle.h"

namespace Meteor {
    void Triangle::Initialize() {
        vertices = { 
            -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f 
        };

        glGenVertexArrays(1, &vertexArrayObject);
        glGenBuffers(1, &vertexBufferObject);

        this->SetShader(OpenGlShaderCompiler::CompileFromFile("Shaders/TriangleVS.glsl", "Shaders/TriangleFS.glsl"));

        glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    void Triangle::Render() {
        this->shader->Use();
        glBindVertexArray(vertexArrayObject);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
    }
}