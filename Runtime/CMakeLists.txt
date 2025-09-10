add_executable(Runtime
    main.cpp
    Scenes/TriangleScene.cpp
    Actors/Triangle.cpp
)

target_link_libraries(Runtime PRIVATE Engine)