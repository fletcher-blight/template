from conans import ConanFile, CMake

class TemplateConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = [ "gtest/1.10.0", "spdlog/1.8.5" ]
    generators = "cmake_find_package"

    name = "Template"
    version = "0.0.1"
    license = "MIT"
    url = "https://github.com/fletcher-blight/template"
    exports_sources = "src/*"

    def configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        return cmake

    def build(self):
        cmake = self.configure_cmake()
        cmake.build()

    def package(self):
        cmake = self.configure_cmake()
        cmake.install()