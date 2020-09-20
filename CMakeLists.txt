cmake_minimum_required(VERSION 3.17)
project(TemplateProject)

# Ensure Top Level
get_directory_property(has_parent PARENT_DIRECTORY)
if(has_parent)
  message(FATAL "Must be top level project, please only add 'src' as sub directory.")
endif()

# Conan Package Management Support
option(ENABLE_CONAN "Enable conan package management" OFF)
if (${ENABLE_CONAN})
    if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
        file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
    endif()
    include("${CMAKE_BINARY_DIR}/conan.cmake")
    conan_cmake_run(CONANFILE conanfile.py BUILD_MISSING)
    list(PREPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")
    list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")
endif()

# Testing Support
option(BUILD_TESTING "Build Tests" OFF)
if (${BUILD_TESTING})
    enable_testing()
endif()

# Project Sources
add_subdirectory(src)
#add_subdirectory(docs)
#add_subdirectory(tests) // full cross module testing
#add_subdirectory(examples)

# CMake Installation Files
set(INSTALL_CMAKEDIR
    "${CMAKE_INSTALL_LIBDIR}/cmake/template/"
    CACHE STRING "Path to Template cmake files")
install(EXPORT TemplateTargets
    DESTINATION "${INSTALL_CMAKEDIR}"
    NAMESPACE   Template::
    FILE        TemplateConfig.cmake)

# Versioning Support
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    TemplateConfigVersion.cmake
    VERSION 0.0.1
    COMPATIBILITY SameMajorVersion)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/TemplateConfigVersion.cmake
    DESTINATION "${INSTALL_CMAKEDIR}")