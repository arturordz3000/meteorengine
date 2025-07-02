find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Add the Engine library
add_library(Engine STATIC
    Base/Declarations.h
    Core/Game.cpp
    Core/Game.h
    Core/IWindow.cpp
    Core/IWindow.h
    Core/Window.cpp
    Core/Window.h
    Core/IApplicationLayer.h
    Events/AbstractEvent.h
    Events/KeyEvent.h
    Events/KeyPressedEvent.h
    Events/KeyReleasedEvent.h
    Graphics/AbstractRenderer.h
    Graphics/AbstractRenderable.h
    Graphics/GraphicsFactory.h
    Graphics/GraphicsFactory.cpp
    Graphics/ICamera.h
    Graphics/IContext.h
    Graphics/OpenGlRenderer.h
    Graphics/OpenGlRenderer.cpp
    Graphics/OpenGlContext.h
    Graphics/OpenGlContext.cpp
    Logger/ILogger.h
    Logger/Logger.h
    Logger/Logger.cpp
    Logger/ConsoleLogger.h
    Logger/ConsoleLogger.cpp
    Utils/TimeUtils.h
    Utils/TimeUtils.cpp
)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Engine OpenGL::GL GLEW::GLEW glfw)