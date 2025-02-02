#pragma once

#include <string>
#include <glm/glm.hpp>
#include <vector>
#include <unordered_map>
#include "Graphics/IShader.h"
#include "Graphics/Texture.h"

namespace Meteor {
    class Material {
        public:
            void SetFloat(const std::string& name, float value);
            float GetFloat(const std::string& name) const;

            void SetVec3(const std::string& name, const glm::vec3& value);
            glm::vec3 GetVec3(const std::string& name) const;

            void AddTexture(const Texture& texture);
            const std::vector<Texture>& GetTextures() const;

            void ApplyToShader(IShader& shader);

        private:
            std::unordered_map<std::string, float> scalars;
            std::unordered_map<std::string, glm::vec3> vectors;
            std::vector<Texture> textures;
    };
}