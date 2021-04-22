option(TESTING "Build and enable tests" OFF)

if (${TESTING})
    enable_testing()
    find_package(GTest REQUIRED)
    add_library(testing-interface INTERFACE)
    target_compile_options(testing-interface INTERFACE -DTESTING=true)
    target_link_libraries(testing-interface INTERFACE GTest::gtest_main GTest::gmock_main)
endif()