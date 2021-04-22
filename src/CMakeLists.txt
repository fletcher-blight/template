cmake_minimum_required(VERSION 3.19)
project(Template)
include(GNUInstallDirs)

# Project Modules
add_subdirectory(foobar)
add_subdirectory(app)

# Project installation targets
install(TARGETS
        foobar foobar-public-interface foobar-private-interface
        app
        EXPORT ${PROJECT_NAME}Targets
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")

# Sub directory compatibility
set_target_properties(foobar PROPERTIES EXPORT_NAME Foobar)
set_target_properties(app PROPERTIES EXPORT_NAME App)
add_library(${PROJECT_NAME}::Foobar ALIAS foobar)