set(sources
        private/main.cpp)

add_library(app-interface INTERFACE)
target_compile_features(app-interface INTERFACE cxx_std_20)
target_link_libraries(app-interface INTERFACE foobar)

add_executable(app ${sources})
target_link_libraries(app PRIVATE app-interface)

if (${TESTING})
    add_executable(test-app ${sources})
    target_link_libraries(test-app PRIVATE app-interface testing-interface)
    add_test(test-app "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test-app")
endif()