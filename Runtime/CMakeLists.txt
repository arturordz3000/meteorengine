add_executable(Runtime
    main.cpp
    Scenes/TestScene.cpp
    Actors/Triangle.cpp
    Actors/Rectangle.cpp
)

add_custom_command(
    TARGET Runtime POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/Runtime/Shaders
            $<TARGET_FILE_DIR:Runtime>/Shaders
)

target_link_libraries(Runtime PRIVATE Engine)