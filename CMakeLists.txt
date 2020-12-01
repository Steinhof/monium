cmake_minimum_required(VERSION 3.17)
project(monium)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE source_list "src/*.cpp" "src/*.h")

add_executable(monium src/main.cpp ${source_list})