cmake_minimum_required(VERSION 3.2)
project(OpenGLEngine VERSION 0.0.1)

file(GLOB engine_files
    "src/*.h"
    "src/*.c"
)

add_executable(OpenGLEngine ${engine_files})

add_library(glad glad/glad.h glad/khrplatform.h glad/glad.c)

target_link_libraries(OpenGLEngine glfw)
target_link_libraries(OpenGLEngine glad)