#include "Graphics/Material.h"
#include "Logger/Logger.h"

namespace Meteor {
    void Material::SetFloat(const std::string& name, float value) {
        scalars[name] = value;
    }

    float Material::GetFloat(const std::string& name) const {
        if (scalars.count(name) == 0) {
            Logger::GetInstance().Error("Scalar property " + name + " not found!");
            return 0.0f;
        }

        return scalars.at(name);
    }

    void Material::SetVec3(const std::string& name, const glm::vec3& value) {
        vectors[name] = value;
    }

    glm::vec3 Material::GetVec3(const std::string& name) const {
        if (vectors.count(name) == 0) {
            Logger::GetInstance().Error("Vector property " + name + " not found!");
            return glm::vec3(0.0f);
        }

        return vectors.at(name);
    }

    void Material::AddTexture(const Texture& texture) {
        textures.push_back(texture);
    }

    const std::vector<Texture>& Material::GetTextures() const {
        return textures;    
    }

    void Material::ApplyToShader(IShader& shader) {
        for (const auto& [name, value] : scalars) {
            shader.SetUniform("material." + name, value);
        }

        for (const auto& [name, value] : vectors) {
            shader.SetUniform("material." + name, value);
        }

        unsigned int textureUnit = 0;
        for (const auto& texture : textures) {
            shader.BindTexture(texture, textureUnit++);
        }
    }
}