cmake_minimum_required (VERSION 3.9.2)

project(entity-system)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/src")

file(GLOB source_files
    "*.hpp"
    "*.cpp"
    "src/*.hpp"
    "src/*.cpp"
    "src/main.cpp"
    "src/EntitySystem.hpp"
    "src/EntitySystem.cpp"
    "src/base-classes/*.hpp"
    "src/base-classes/*.cpp"
	"src/data-container/*.hpp"
	"src/data-container/*.cpp"
	"src/data-validation/*.hpp"
	"src/data-validation/*.cpp"
	"src/entity-manager/*.hpp"
	"src/entity-manager/*.cpp"
	"src/entity-manager/entity-attribute-manager/*.hpp"
	"src/entity-manager/entity-attribute-manager/*.cpp"
	"src/entity-manager/entity-attribute-manager/entity-attribute-type/*.hpp"
	"src/entity-manager/entity-attribute-manager/entity-attribute-type/*.cpp"
	"src/entity-manager/entity-attribute-manager/entity-attribute-type-instances/*.hpp"
	"src/entity-manager/entity-attribute-manager/entity-attribute-type-instances/*.cpp"
	"src/entity-manager/entity-relation-attribute-manager/*.hpp"
	"src/entity-manager/entity-relation-attribute-manager/*.cpp"
	"src/entity-manager/entity-relation-attribute-manager/entity-relation-attribute-type/*.hpp"
	"src/entity-manager/entity-relation-attribute-manager/entity-relation-attribute-type/*.cpp"
	"src/entity-manager/entity-relation-attribute-manager/entity-relation-attribute-type-instance/*.hpp"
	"src/entity-manager/entity-relation-attribute-manager/entity-relation-attribute-type-instance/*.cpp"
	"src/entity-manager/entity-relation-manager/*.hpp"
	"src/entity-manager/entity-relation-manager/*.cpp"
	"src/entity-manager/entity-relation-manager/entity-relation-type/*.hpp"
	"src/entity-manager/entity-relation-manager/entity-relation-type/*.cpp"
	"src/entity-manager/entity-relation-manager/entity-relation-type-instance/*.hpp"
	"src/entity-manager/entity-relation-manager/entity-relation-type-instance/*.cpp"
	"src/entity-manager/entity-type-manager/*.hpp"
	"src/entity-manager/entity-type-manager/*.cpp"
	"src/entity-manager/entity-type-manager/entity-type/*.hpp"
	"src/entity-manager/entity-type-manager/entity-type/*.cpp"
	"src/entity-manager/entity-type-manager/entity-type-instance/*.hpp"
	"src/entity-manager/entity-type-manager/entity-type-instance/*.cpp"
	"src/error-handling/*.hpp"
	"src/error-handling/*.cpp"
	"src/return-codes/*.hpp"
	"src/return-codes/*.cpp"
	"src/templates/*.hpp"
	"src/templates/*.cpp"
	"src/typedefs/*.hpp"
	"src/typedefs/*.cpp"
)

add_executable(entity-system ${source_files})
