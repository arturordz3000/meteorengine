add_executable(Runtime
    main.cpp
    Scenes/CubeScene.cpp
)

target_link_libraries(Runtime PRIVATE Engine)