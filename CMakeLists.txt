cmake_minimum_required (VERSION 3.4)

project(inexor-entity-system)

# Use folder structure in Visual Studio.
function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)


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
conan_add_remote(NAME helmesjo INDEX 1
            URL https://api.bintray.com/conan/helmesjo/public-conan)

if(UNIX AND NOT APPLE)
    set(LIBCXX libstdc++11)
endif()

if(UNIX AND NOT APPLE)
	conan_cmake_run(CONANFILE conanfile.txt
        	        BASIC_SETUP
                	BUILD outdated
                	PROFILE default
                	PROFILE_AUTO build_type
			SETTINGS compiler.libcxx=${LIBCXX})
else()
	conan_cmake_run(CONANFILE conanfile.txt
			BASIC_SETUP
			BUILD outdated
			PROFILE default
			PROFILE_AUTO build_type)
endif()

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

# all non-test source files minus the main.cpp are going to the library
set(LIBRARY_SOURCE_FILES ${NORMAL_SOURCE_FILES})
list(REMOVE_ITEM LIBRARY_SOURCE_FILES "src/main.cpp")

# Compile external files into the application binary
find_package(Corrade REQUIRED Utility)
#set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)
corrade_add_resource(CORRADE_STANDALONE_RESOURCES standalone-resources.conf)

message(STATUS "NORMAL SOURCE FILES: ${NORMAL_SOURCE_FILES} + src/main.cpp")
message(STATUS "TEST SOURCE FILES: ${TEST_SOURCE_FILES}")
message(STATUS "CONAN_LIBS: ${CONAN_LIBS}")
message(STATUS "CORRADE_STANDALONE_RESOURCES: ${CORRADE_STANDALONE_RESOURCES}")

add_library(inexor-entity-system-lib ${LIBRARY_SOURCE_FILES})
target_link_libraries(inexor-entity-system-lib ${CONAN_LIBS})
#if(APPLE) <- Fohlen, can you verify this is not needed?
    # target_link_libraries(inexor-entity-system-lib "-framework CoreFoundation")
#endif()

# add_executable(inexor-entity-system-standalone src/main.cpp)
add_executable(inexor-entity-system-standalone src/main.cpp ${CORRADE_STANDALONE_RESOURCES})
target_link_libraries(inexor-entity-system-standalone PUBLIC inexor-entity-system-lib)
target_link_libraries(inexor-entity-system-standalone PUBLIC ${CONAN_LIBS})
target_link_libraries(inexor-entity-system-standalone PRIVATE Corrade::Utility)
if(APPLE)
    target_link_libraries(inexor-entity-system-standalone "-framework CoreFoundation")
endif()

add_executable(inexor-entity-system-tests ${TEST_SOURCE_FILES})
target_link_libraries(inexor-entity-system-tests inexor-entity-system-lib)
target_link_libraries(inexor-entity-system-tests ${CONAN_LIBS})

# Use folder structure in Visual Studio.
assign_source_group(${NORMAL_SOURCE_FILES})
assign_source_group(${TEST_SOURCE_FILES})

