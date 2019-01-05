cmake_minimum_required (VERSION 3.4)

project(entity-system)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)

# Dependency setup via conan

# Download conan executer in case it does not exists
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.13/conan.cmake"
                 "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)

conan_check(VERSION 1.4.0 REQUIRED)
conan_add_remote(NAME bincrafters INDEX 1
            URL https://api.bintray.com/conan/bincrafters/public-conan)
conan_add_remote(NAME inexor INDEX 1
            URL https://api.bintray.com/conan/inexorgame/inexor-conan)

conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP
                BUILD missing
                PROFILE default
                PROFILE_AUTO build_type)

include_directories("${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE source_files
  "src/*.hpp"
  "src/*.cpp"
)

# Two targets: entity-system library and unit_test
# Each file with "_test" in its name is a file added to unit_test
set(normal_source_files)
set(test_source_files)
foreach(file ${source_files} )
  if(file MATCHES ".*_test.*" )
     set(test_source_files ${test_source_files} ${file})
  else()
     set(normal_source_files ${normal_source_files} ${file})
  endif()
endforeach()

message(STATUS "NORMAL SOURCE FILES: ${normal_source_files}")
message(STATUS "TEST SOURCE FILES: ${test_source_files}")

add_library(entity-system ${normal_source_files})
add_executable(entity-system-tests ${test_source_files})
target_link_libraries(entity-system-tests entity-system)

if(UNIX AND APPLE)
    target_link_libraries(entity-system "-framework CoreFoundation")
endif()

target_link_libraries(entity-system ${CONAN_LIBS})
target_link_libraries(entity-system-tests ${CONAN_LIBS})
