cmake_minimum_required(VERSION 3.15)

project(ball_territory_war)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

file(GLOB SOURCES "src/*.cpp")

add_executable(ball_territory_war ${SOURCES})
