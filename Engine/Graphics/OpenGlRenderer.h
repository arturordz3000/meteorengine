#pragma once

#include "Graphics/AbstractRenderer.h"
#include "Graphics/OpenGlContext.h"

namespace Meteor {
    class OpenGlRenderer : public AbstractRenderer {
        public:
            OpenGlRenderer(IWindow& window) : m_Window(window) {} 
            void virtual Initialize() override;
            void virtual Render() override;
            void virtual StartScene(ICamera& camera) override;
            void virtual EndScene() override;
        private:
            void SetupOpenGl();
            void SetupShaders();

            IWindow& m_Window;
            GLFWwindow* m_NativeWindow;
    };
}