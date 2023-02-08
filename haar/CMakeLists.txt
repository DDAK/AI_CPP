cmake_minimum_required(VERSION 2.8.12)
project(haar)
# C++ standard 
add_compile_options(-std=c++20)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Using the "cmake" generator from conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(haar haar.cpp)
target_link_libraries(haar CONAN_PKG::opencv)
