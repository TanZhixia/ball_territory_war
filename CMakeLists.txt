cmake_minimum_required(VERSION 3.15)

project(ball_territory_war)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

file(GLOB SOURCES "src/*.cpp")

add_executable(ball_territory_war ${SOURCES})

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt")

find_package(SFML 3 COMPONENTS Graphics Window System Audio Network REQUIRED)

find_package(OpenCV 4 REQUIRED)

target_link_libraries(ball_territory_war PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
    ${OpenCV_LIBRARIES}
)

target_include_directories(ball_territory_war PRIVATE
    include
)
