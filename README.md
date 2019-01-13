# Inexor entity-system prototype

This entity-system will lay the basis on the other systems of the game will be built on.
For more information take a look at the [wiki](https://inexor.org/wiki/features/entities/#the-goal).

## Prerequirements

To build the entity-system one needs:

- a compiler of choice (`gcc`, `clang`, `MSVC`)
- `cmake`
- [`conan`](https://conan.io)

## Build

- `mkdir build && cd build`
- `cmake ..` (creates project files, can also be done via gui)
- `cmake --build .` (compiles the project)

## Documentation

You need to run `doxygen` (retrievable from http://doxygen.nl/) inside this folder to create the docs at the moment.
