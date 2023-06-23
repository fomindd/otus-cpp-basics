cmake_minimum_required(VERSION 3.10)

project(homework_4 CXX)

add_executable(homework_4
    src/lexer.cpp
    src/parser.cpp
    src/astnode.cpp
    src/main.cpp
)

target_include_directories(homework_4 PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(homework_4 PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(homework_4 PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(homework_4 PUBLIC cxx_std_17)
