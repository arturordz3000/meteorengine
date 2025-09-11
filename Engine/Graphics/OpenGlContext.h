#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/IContext.h"
#include "Logger/Logger.h"

namespace Meteor {
    class OpenGlContext : public IContext {
        public:
            OpenGlContext(IWindow& window) : m_Window(window) { Initialize(window); }

            virtual IWindow& GetWindow() const override;
            virtual void* GetNativeWindow() const override;
            virtual void SwapBuffers() override;
        private:
            void Initialize(IWindow& window);

            IWindow& m_Window;
            GLFWwindow* m_NativeWindow;
    };
}   