#pragma once

#include "Graphics/IContext.h"

namespace Meteor {
    class OpenGlContext : public IContext {
        public:
            OpenGlContext(IWindow& window)
             : m_Window(window) { Initialize(); }

            virtual IWindow& GetWindow() const override;
            virtual void SwapBuffers() override;
        private:
            void Initialize();

            IWindow& m_Window;
            GLFWwindow* m_NativeWindow;
    };
}