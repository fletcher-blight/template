cmake_minimum_required(VERSION 3.17)
project(TemplateProject)

include(GNUInstallDirs)

# Project Modules
add_subdirectory(foo)
add_subdirectory(bar)

# Project installation targets
install(TARGETS 
    # Foo
    foo foo-interface
    # Bar
    bar
    EXPORT TemplateTargets
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")

# Sub directory compatability
set_target_properties(foo PROPERTIES EXPORT_NAME Foo)
set_target_properties(bar PROPERTIES EXPORT_NAME Bar)
add_library(Template::Foo ALIAS foo)