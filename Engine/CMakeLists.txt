find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Add the Engine library
add_library(Engine STATIC
    Core/Game.cpp
    Core/IWindow.cpp
    Core/Window.cpp
    Core/File.cpp
    Graphics/AbstractRenderable3d.cpp
    Graphics/GraphicsFactory.cpp
    Graphics/OpenGlRenderer.cpp
    Graphics/OpenGlContext.cpp
    Graphics/OpenGlShaderCompiler.cpp
    Graphics/OpenGlShader.cpp
    Logger/Logger.cpp
    Logger/ConsoleLogger.cpp
    Utils/TimeUtils.cpp
    Utils/FileSystemUtils.cpp
)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Engine OpenGL::GL GLEW::GLEW glfw)