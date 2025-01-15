find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Add the Engine library
add_library(Engine STATIC
    Base/Declarations.h
    Core/Application.cpp
    Core/Application.h
    Core/IWindow.cpp
    Core/IWindow.h
    Core/Window.cpp
    Core/Window.h
    Events/IEvent.h
    Events/KeyEvent.h
    Events/KeyPressedEvent.h
    Events/KeyReleasedEvent.h
)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Engine OpenGL::GL GLEW::GLEW glfw)