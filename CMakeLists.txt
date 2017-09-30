cmake_minimum_required(VERSION 3.8)
project(GravityShowed)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lGLEW -lglfw3 -lGL -lX11 -lXrandr -Wall -ldl -lpthread -lXi -lm -lGLU")
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

set(SOURCE_FILES main.cpp Shaders.cpp Shaders.h Vectors.h Vectors.cpp Physics.cpp Physics.h)
add_executable(GravityShowed ${SOURCE_FILES})
target_link_libraries(GravityShowed glfw GLEW GL)