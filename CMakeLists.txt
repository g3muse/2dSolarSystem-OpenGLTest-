cmake_minimum_required(VERSION 3.9)
project(workingOpenGL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

include_directories("~/Documents/OpenGL\ Libraries/include")
link_directories("~/Documents/OpenGL\ Libraries/lib")

add_executable(planets main.cpp)