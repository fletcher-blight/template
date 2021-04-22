# CMake Installation Files
set(INSTALL_CMAKEDIR
        "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}/"
        CACHE STRING "Path to ${PROJECT_NAME} cmake files")
install(EXPORT ${PROJECT_NAME}Targets
        DESTINATION "${INSTALL_CMAKEDIR}"
        NAMESPACE   ${PROJECT_NAME}::
        FILE        ${PROJECT_NAME}Config.cmake)

# Versioning Support
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${PROJECT_NAME}ConfigVersion.cmake
        VERSION 0.0.1
        COMPATIBILITY SameMajorVersion)
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION "${INSTALL_CMAKEDIR}")