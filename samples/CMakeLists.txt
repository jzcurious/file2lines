cmake_minimum_required(VERSION 3.24)
project(file2lines-samples LANGUAGES CXX)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_executable(file2lines-samples ${SRC})

target_include_directories(file2lines-samples PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
target_link_libraries(file2lines-samples PRIVATE
    file2lines
)
