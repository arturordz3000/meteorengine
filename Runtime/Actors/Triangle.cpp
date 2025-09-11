#include "Triangle.h"

namespace Meteor {
    void Triangle::Initialize() {
        vertices = { 
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f 
        };

        glGenVertexArrays(1, &vertexArrayObject);
        glGenBuffers(1, &vertexBufferObject);

        const std::string vs =
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main(){ gl_Position = vec4(aPos, 1.0); }\n";

        const std::string fs =
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main(){ FragColor = vec4(1.0, 0.5, 0.2, 1.0); }\n";

        this->SetShader(OpenGlShaderCompiler::CompileFromSource(vs, fs));

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