cmake_minimum_required(VERSION 3.28)
project(BabyBird LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(BabyBird src/main.cpp "src/Entity.h"  "src/Systems/System.h"  "src/Game.h" "src/Game.cpp" "src/Components/VelocityComponent.h" "src/Components/SpriteComponent.h" "src/pch.h" "src/Systems/RenderSystem.h" "src/Systems/RenderSystem.cpp" "src/Systems/MovementSystem.cpp" "src/Systems/MovementSystem.h" "src/Systems/SpawnerSystem.h" "src/Systems/SpawnerSystem.cpp" "src/Components/InputComponent.h" "src/Systems/InputSystem.h" "src/Systems/InputSystem.cpp" "src/Animation/Animation.h")
target_compile_features(BabyBird PRIVATE cxx_std_17)
target_link_libraries(BabyBird PRIVATE SFML::Graphics)
