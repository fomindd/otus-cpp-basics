cmake_minimum_required(VERSION 3.2)

project(containers_tests)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)

# Test target
add_executable(
    containers_tests
    test/vector_tests.cpp
    test/list_tests.cpp
    test/run_tests.cpp
)

target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

target_compile_options(
    containers_tests PRIVATE
    -Wall -Wextra -pedantic -Werror
)