# Interface of the library
add_library(foo-interface INTERFACE)
target_include_directories(foo-interface INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_compile_features(foo-interface INTERFACE cxx_std_17)

# Source files
set(sources
    private/math.cpp
    public/foo/math.hpp)

# The main foo library
add_library(foo ${sources})
target_link_libraries(foo PUBLIC foo-interface)

# Tests
if (${BUILD_TESTING})
    find_package(GTest REQUIRED)

    # Unit testing inside source files.
    add_executable(foo-unit-tests ${sources})
    target_compile_definitions(foo-unit-tests PRIVATE BUILD_TESTING)
    target_link_libraries(foo-unit-tests PRIVATE foo-interface GTest::GTest)

    # System testing which links to the library
    add_executable(foo-system-tests tests/add.cpp)
    target_link_libraries(foo-system-tests PRIVATE foo GTest::GTest)

    # CTest support
    add_test(foo-system-tests "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/foo-system-tests")
    add_test(foo-unit-tests "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/foo-unit-tests")
endif()

# Installation needs to copy public files.
install(DIRECTORY public/
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")