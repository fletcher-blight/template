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
