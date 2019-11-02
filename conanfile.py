from conans import ConanFile, CMake

class InexorConan(ConanFile):

    settings = (
        "os",
        "compiler",
        "build_type",
        "arch"
    )

    requires = (
        "glm/0.9.9.5",
        "gtest/1.8.1",
        "benchmark/1.5.0",

        "boost_property_tree/1.69.0@bincrafters/stable",
        "boost_signals2/1.69.0@bincrafters/stable",
        "freetype/2.9.1@bincrafters/stable",
        "openal/1.19.0@bincrafters/stable",
        "spdlog/1.3.0@bincrafters/stable",

        "magic_enum/0.6.3@neargye/stable",

        "boost-di/1.1.0@inexorgame/stable",
        "boost-te/19.Jan.19@inexorgame/stable",
        "cpp.react/legacy1@inexorgame/stable",

        "crossguid/06-03-19@inexorgame/testing",
        "magnum/2019.01@inexorgame/testing",
        "magnum_plugins/2019.01@inexorgame/testing"
    )

    generators = "cmake"

    default_options = {
        "magnum:build_plugins_static": True,
        "magnum:with_glfwapplication": True,
        "magnum:with_sdl2application": False,
        "magnum:with_audio": True,
        "magnum:with_anyaudioimporter": True,
        "magnum:with_anyimageimporter": True,
        "magnum:with_anyimageconverter": True,
        "magnum:with_anysceneimporter": True,
        "magnum_plugins:with_tinygltfimporter": True,
        "magnum_plugins:with_stbimageimporter": True,
        "magnum_plugins:with_stbimageconverter": True,
        "magnum_plugins:with_stbvorbisaudioimporter": True,
        "magnum_plugins:with_stbtruetypefont": True,
        "magnum_plugins:with_freetypefont": True,
        "magnum_plugins:build_plugins_static": True,
        "TBB:shared": True,
    }

    def imports(self):
        # Copies all dll files from packages bin folder to my "bin" folder (win)
        self.copy("*.dll", dst="bin", src="bin")
        # Copies all dylib files from packages lib folder to my "lib" folder (macosx)
        self.copy("*.dylib*", dst="lib", src="lib") # From lib to lib
        # Copies all so files from packages lib folder to my "lib" folder (linux)
        self.copy("*.so*", dst="lib", src="lib") # From lib to lib

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
