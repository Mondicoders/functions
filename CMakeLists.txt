cmake_minimum_required(VERSION 3.20)
project(functions)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(OpenGLEngine)

add_executable(functions function_parser.cpp main.cpp)

target_link_libraries(functions glfw OpenGL::GL)
target_include_directories(functions PRIVATE OpenGLEngine)
