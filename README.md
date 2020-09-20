# Template Project

## Usages

### Installing

    cmake -S . -B build
    cmake --build build --target install

### Create Conan Package

    conan create .

### Maintainer

    cmake -S . -B build -DBUILD_TESTING=ON -DENABLE_CONAN=ON -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
    cmake --build build --target test

### Consumer

    // as a submodule, add the src directory not the root
    add_subdirectory(submodules/template/src)

    // as an installed package, find the components you need
    find_package(Template COMPONENTS Foo)


## Notes
---

- Conan is optional. ENABLE_CONAN will use the requirements from the conanfile.py and link the dependencies using the conan package management system. If you have the required dependencies installed to your system you do not need this option.
- Conan will honour the CMAKE_TOOLCHAIN_FILE configuration. If you are cross compiling and want to use conan dependency management, just use cmake as normal with the required toolchain. Then the os, compiler, archiecture, etc configurations will be used to ensure the conan dependencies are compatabile.