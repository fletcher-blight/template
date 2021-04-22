cmake_minimum_required(VERSION 3.19)
project(Template)

get_directory_property(has_parent PARENT_DIRECTORY)
if(has_parent)
    message(FATAL "Must be top level project, please only add 'src' as sub directory.")
endif()

include(config/conan.cmake)
include(config/testing.cmake)
add_subdirectory(src)
include(config/installation.cmake)