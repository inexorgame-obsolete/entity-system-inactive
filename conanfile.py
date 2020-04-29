from conans import ConanFile, CMake

class InexorConan(ConanFile):

    settings = (
        "os",
        "compiler",
        "build_type",
        "arch"
    )

    requires = (
        "spdlog/1.5.0",
		"glfw/3.3.2@bincrafters/stable",
        "crossguid/06-03-19@inexorgame/testing",
		"boost/1.72.0",
        "magic_enum/0.6.3@neargye/stable",
        "cpp.react/legacy1@inexorgame/stable",
		"glm/0.9.9.8",	
		"benchmark/1.5.0",
		"gtest/1.10.0",
		"nlohmann_json/3.7.3",
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
