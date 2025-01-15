cmake_minimum_required(VERSION 3.24)
project(file2lines-lib LANGUAGES CXX)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_library(file2lines STATIC ${SRC})

target_include_directories(file2lines PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
