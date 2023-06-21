cmake_minimum_required (VERSION 3.8)

add_executable (TEST "test_list.cpp" "test_seq.cpp"  "list_container.hpp" "seq_container.hpp")

target_include_directories(
    TEST PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_include_directories(
    TEST PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
    TEST PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)

if (MSVC)
    target_compile_options(
        MyCMAKE_TEST PRIVATE
        /W4
    )
else ()
    target_compile_options(
        MyCMAKE_TEST PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

target_include_directories(calc PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(calc PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(calc PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(calc PUBLIC cxx_std_17)