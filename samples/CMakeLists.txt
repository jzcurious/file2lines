cmake_minimum_required(VERSION 3.24)
project(txt2lines-samples LANGUAGES CXX)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_executable(txt2lines-samples ${SRC})

target_include_directories(txt2lines-samples PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
target_link_libraries(txt2lines-samples PRIVATE
    txt2lines
)
