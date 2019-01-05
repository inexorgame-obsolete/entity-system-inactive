cmake_minimum_required (VERSION 3.4)

project(entity-system)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (CMAKE_CXX_STANDARD 17)

# Download dependencies
message(${CMAKE_CURRENT_SOURCE_DIR})
include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/crossguid/include")



# Collect all source files for the entity-system
file(GLOB_RECURSE source_files
  "src/*.hpp"
  "src/*.cpp"
)

set(normal_source_files)
foreach(file ${source_files} )
  set(normal_source_files ${normal_source_files} ${file})
endforeach()

message(STATUS "NORMAL SOURCE FILES: ${normal_source_files}")

add_executable(entity-system ${normal_source_files})



# Collect all source files for he unit tests
file(GLOB_RECURSE source_files
  "tests/*.hpp"
  "tests/*.cpp"
)

set(test_source_files)
foreach(file ${source_files} )
  set(test_source_files ${test_source_files} ${file})
endforeach()

message(STATUS "TEST SOURCE FILES: ${test_source_files}")

add_executable(tests ${test_source_files})



if(UNIX AND APPLE)
    target_link_libraries(entity-system "-framework CoreFoundation")
endif()

if(WIN32)
    target_link_libraries(entity-system "${CMAKE_SOURCE_DIR}/dependencies/crossguid/build/libcrossguid.lib")
endif()

if(UNIX AND APPLE)
    target_link_libraries(entity-system "${CMAKE_SOURCE_DIR}/dependencies/crossguid/build/libcrossguid.a")
endif()

target_link_libraries(entity-system ${CONAN_LIBS})
target_link_libraries(tests ${CONAN_LIBS})
