cmake_minimum_required(VERSION 3.9)
project(Gravity)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

link_directories(/usr/local/include)
add_executable(Gravity main.cpp Physics.cpp Scene.cpp)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

include_directories( ${GLM_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS}  ${GLFW_INCLUDE_DIRS})
target_link_libraries(Gravity glfw)