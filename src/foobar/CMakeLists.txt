set(sources
        private/bar.cpp
        public/foo/bar.hpp)

find_package(spdlog 1.8 REQUIRED)

add_library(foobar-public-interface INTERFACE)
add_library(foobar-private-interface INTERFACE)

target_compile_features(foobar-public-interface INTERFACE cxx_std_20)
target_include_directories(foobar-public-interface INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(foobar-private-interface
        INTERFACE
        foobar-public-interface
        spdlog::libspdlog)


add_library(foobar ${sources})
target_link_libraries(foobar
    PUBLIC foobar-public-interface
    PRIVATE foobar-private-interface)

# Installation needs to copy public files.
include(GNUInstallDirs)
install(DIRECTORY public/
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

if (${TESTING})
    add_executable(test-foobar ${sources})
    target_link_libraries(test-foobar PRIVATE foobar-private-interface testing-interface)
    add_test(test-foobar "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test-foobar")
endif()