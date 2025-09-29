#include "Rectangle.h"

namespace Meteor {
    void Rectangle::Initialize() {
        vertices = { 
            1.0f,  0.5f, 0.0f,  // top right
            1.0f, -0.5f, 0.0f,  // bottom right
            0.0f, -0.5f, 0.0f,  // bottom left
            0.0f,  0.5f, 0.0f   // top left 
        };

        indices = {
            0,1,3,
            1,2,3
        };

        glGenVertexArrays(1, &vertexArrayObject);
        glGenBuffers(1, &vertexBufferObject);
        glGenBuffers(1, &elementBufferObject);

        this->SetShader(OpenGlShaderCompiler::CompileFromFile("Shaders/RectangleVS.glsl", "Shaders/RectangleFS.glsl"));

        glBindVertexArray(vertexArrayObject);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    void Rectangle::Render() {
        this->shader->Use();
        glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}