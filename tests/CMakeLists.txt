cmake_minimum_required(VERSION 3.24)
project(txt2lines-tests LANGUAGES CXX)

include(GoogleTest)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_executable(txt2lines-tests ${SRC})

target_include_directories(txt2lines-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
target_link_libraries(txt2lines-tests PRIVATE
    txt2lines
    GTest::gtest_main
)

enable_testing()
gtest_discover_tests(txt2lines-tests)
