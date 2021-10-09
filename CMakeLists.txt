cmake_minimum_required(VERSION 3.19)
project(librtj C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(rtj SHARED linked_list.c)
add_executable(librtj_test_driver main.c)

target_link_libraries(librtj_test_driver rtj)
