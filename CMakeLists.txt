cmake_minimum_required(VERSION 3.28.3)
project(linux_utils C)

set(CMAKE_C_STANDARD 23)

file(GLOB UTIL_SOURCES "src/*.c")

foreach(util_src ${UTIL_SOURCES})
    get_filename_component(util_name ${util_src} NAME_WE)
    add_executable(${util_name} ${util_src})
endforeach()
