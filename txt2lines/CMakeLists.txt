cmake_minimum_required(VERSION 3.24)
project(txt2lines-lib LANGUAGES CXX)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_library(txt2lines STATIC ${SRC})

target_include_directories(txt2lines PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
