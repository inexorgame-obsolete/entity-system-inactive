cmake_minimum_required (VERSION 3.4)

project(entity-system)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (CMAKE_CXX_STANDARD 17)

# Quick fix from Hanni to make it work on Windows
if(NOT WIN32)
  message(${CMAKE_CURRENT_SOURCE_DIR})
  include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
  conan_basic_setup()
endif()

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/crossguid/include")

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

# Quick fix from Hanni to make it work on Windows
if(WIN32)
    target_link_libraries(entity-system "${CMAKE_SOURCE_DIR}/dependencies/crossguid/build/libcrossguid.lib")
endif()

if(UNIX AND APPLE)
    target_link_libraries(entity-system "${CMAKE_SOURCE_DIR}/dependencies/crossguid/build/libcrossguid.a")
endif()
target_link_libraries(entity-system ${CONAN_LIBS})
target_link_libraries(entity-system-tests ${CONAN_LIBS})
