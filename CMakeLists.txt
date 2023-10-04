cmake_minimum_required(VERSION 3.20)
project(IMU_orientation)

set(CMAKE_CXX_STANDARD 20)

add_executable(imr_parser main.cpp
        parse_header.cpp)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(imr_parser PRIVATE
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(imr_parser PRIVATE
            /EHsc
            /W4
            /WX
    )
endif()