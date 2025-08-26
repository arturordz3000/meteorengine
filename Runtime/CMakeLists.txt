add_executable(Runtime
    main.cpp
    Scenes/TriangleScene.cpp
)

target_link_libraries(Runtime PRIVATE Engine)