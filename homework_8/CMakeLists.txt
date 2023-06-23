cmake_minimum_required(VERSION 3.15)

project(homework_8 LANGUAGES CXX)

find_package(Threads REQUIRED)

add_executable(homework_8 main.cpp)

target_link_libraries(homework_8 PUBLIC Threads::Threads)

set_target_properties(homework_8 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)