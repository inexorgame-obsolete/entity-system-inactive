# Inexor entity-component-system prototype
[![Build Status](https://travis-ci.org/inexorgame/entity-system.svg?branch=master)](https://travis-ci.org/inexorgame/entity-system)

Inexor is a new octree-based game+engine based on C++17 and Vulkan API. It's core design feature is an entity-component-system (ECS).

## How is Inexor organized?

We are a headless collective. This means we are simply a group of people with different ideas working together without a leader making all the decisions. Anyone of us is free to work on the particular things they want to.
For this organization to work properly we rely on good communication. Join our discord server!

We are open for new people!

## The entity-system

The entity-system will lay the basis on the other systems of the game will be built on.
For more information take a look at the [wiki](https://inexor.org/wiki/features/Entity-System.html).

## Build process

Building the `entity-system` is quite straightforward:

### Prerequirements

To build the entity-system one needs:

- a compiler of choice (`gcc`, `clang`, `MSVC`)
- `cmake`
- [`conan`](https://conan.io)

### Building

- `mkdir build && cd build`
- `cmake ..` (creates project files, can also be done via gui)
- `cmake --build .` (compiles the project)
    - `MAKEFLAGS=-j8 cmake --build .` (compiles the project with 8 cores)

### Documentation

You need to install
- `doxygen`  (retrievable from http://doxygen.nl/)
- `graphviz` see [their website](https://www.graphviz.org/)

Once installed invoke `doxygen` from the `entity-system` directoy like so:

`doxygen`

## Join us

Join our [Discord](https://discord.gg/acUW8k7.)! 

To contribute to the project and merge your changes into the master branch you need to convince enough members that the changes are an improvement.
It probably won't be an issue. However you should still communicate what you're doing and why you are doing it and of course take feedback and tips from others into account.

More information about the contributing process can be found [here](https://github.com/inexorgame/inexor-core/wiki/How-To-Contribute-Code).
