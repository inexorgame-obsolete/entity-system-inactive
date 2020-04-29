cmake_minimum_required(VERSION 3.7)

# Entity Component System (ECS)
project(inexor-ecs)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
		
option(INEXOR_ECS_BUILD_BENCHMARKS "Build benchmarks" OFF)
#option(INEXOR_ECS_BUILD_DOC "Build documentation" OFF) // TODO
option(INEXOR_ECS_BUILD_EXAMPLE "Build example" ON)
option(INEXOR_ECS_BUILD_TESTS "Build tests" OFF)

set(INEXOR_CONAN_PROFILE "default" CACHE STRING "conan profile")

# Set output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

message(STATUS "INEXOR_ECS_BUILD_BENCHMARKS = ${INEXOR_BUILD_BENCHMARKS}")
#TODO:
#message(STATUS "INEXOR_ECS_BUILD_DOC = ${INEXOR_BUILD_DOC}")
message(STATUS "INEXOR_ECS_BUILD_EXAMPLE = ${INEXOR_BUILD_EXAMPLE}")
message(STATUS "INEXOR_ECS_BUILD_TESTS= ${INEXOR_BUILD_TESTS}")
message(STATUS "INEXOR_CONAN_PROFILE = ${INEXOR_CONAN_PROFILE}")

message(STATUS "CMAKE_VERSION = ${CMAKE_VERSION}")
message(STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}")
message(STATUS "C Compiler executable: ${CMAKE_C_COMPILER}")
message(STATUS "CXX Compiler executable: ${CMAKE_CXX_COMPILER}")
message(STATUS "Linker executable: ${CMAKE_LINKER}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(MSVC2019_COMPATIBILITY ON)

add_subdirectory(submodules/corrade)
add_subdirectory(submodules/magnum)
#add_subdirectory(submodules/magnum-plugins)
add_subdirectory(third_party/magnum-plugins)
add_subdirectory(third_party/boost-di)

# Dependency setup via conan.
# Download conan executer in case it does not exists.
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.14/conan.cmake"
                 "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
endif()

# Execute conan build instructions.
include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

# Dependency setup with conan
conan_check(VERSION 1.19.1 REQUIRED)

conan_add_remote(NAME bincrafters
                 INDEX 1
                 URL https://api.bintray.com/conan/bincrafters/public-conan)
conan_add_remote(NAME inexor
                 INDEX 2
                 URL https://api.bintray.com/conan/inexorgame/inexor-conan)
conan_add_remote(NAME helmesjo
                 INDEX 3
                 URL https://api.bintray.com/conan/helmesjo/public-conan)
conan_add_remote(NAME neargye
                 INDEX 4
                 URL https://api.bintray.com/conan/neargye/conan-packages)
				 
conan_cmake_run(CONANFILE conanfile.py
	BASIC_SETUP
	BUILD outdated
	PROFILE default
	PROFILE_AUTO build_type
	KEEP_RPATHS
)					

# TODO: Include only the stuff that is needed!
find_package(Magnum REQUIRED Trade)
find_package(Corrade REQUIRED Utility)
find_package(MagnumPlugins REQUIRED)

add_subdirectory(src)

if(${INEXOR_ECS_BUILD_BENCHMARKS})
    add_subdirectory(benchmarks)
endif()

if(${INEXOR_ECS_BUILD_DOC})
    add_subdirectory(documentation)
endif()

if(${INEXOR_ECS_BUILD_EXAMPLE})
    add_subdirectory(example)
endif()

if(${INEXOR_ECS_BUILD_TESTS})
    add_subdirectory(tests)
endif()
