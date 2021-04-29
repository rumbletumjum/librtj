cmake_minimum_required(VERSION 3.19)
project(foo_list C)

set(CMAKE_C_STANDARD 99)

add_library(rtj SHARED linked_list.c)
add_executable(foo_list main.c)

target_link_libraries(foo_list rtj)