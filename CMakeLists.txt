cmake_minimum_required (VERSION 3.4)

project(inexor-entity-system)

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

# Two targets: inexor-entity-system library and unit_test
# Each file with "_test" in its name is a file added to unit_test
set(NORMAL_SOURCE_FILES)
set(TEST_SOURCE_FILES)
foreach(file ${source_files} )
  if(file MATCHES ".*_test.*" )
     set(TEST_SOURCE_FILES ${TEST_SOURCE_FILES} ${file})
  else()
     set(NORMAL_SOURCE_FILES ${NORMAL_SOURCE_FILES} ${file})
  endif()
endforeach()

message(STATUS "NORMAL SOURCE FILES: ${NORMAL_SOURCE_FILES}")
message(STATUS "TEST SOURCE FILES: ${TEST_SOURCE_FILES}")
message(STATUS "CONAN_LIBS: ${CONAN_LIBS}")

# Hanni: Try to solve MSVC 2017 problems with C++2017.
set_target_properties(inexor-entity-system PROPERTIES
   CXX_STANDARD 17
)

add_library(inexor-entity-system ${NORMAL_SOURCE_FILES})
add_executable(inexor-entity-system-standalone ${NORMAL_SOURCE_FILES})
add_executable(inexor-entity-system-tests ${TEST_SOURCE_FILES})
target_link_libraries(inexor-entity-system-tests inexor-entity-system)

if(UNIX AND APPLE)
    target_link_libraries(inexor-entity-system "-framework CoreFoundation")
    target_link_libraries(inexor-entity-system-standalone "-framework CoreFoundation")
endif()

target_link_libraries(inexor-entity-system ${CONAN_LIBS})
target_link_libraries(inexor-entity-system-standalone ${CONAN_LIBS})
target_link_libraries(inexor-entity-system-tests ${CONAN_LIBS})
