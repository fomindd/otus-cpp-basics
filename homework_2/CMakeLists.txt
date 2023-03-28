cmake_minimum_required(VERSION 3.15)

project(01.hello_world CXX)

add_executable(hello_world 
    hello_world.cpp
    move_me_out.cpp
    move_me_out.h
    example.cpp
    example.h
)

set_target_properties(hello_world PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
  CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    target_compile_options(hello_world PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

    target_compile_options(hello_world PRIVATE /EHsc /W4 /WX)

endif()
