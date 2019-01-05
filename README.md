# Inexor entity-system prototype
The development of a new and thread-safe entity-system is an essential requirement for the future of Inexor.
This entity-system will lay the basis on which most of the other systems of the engine will be built on.
For more information take a look at the [wiki](https://github.com/inexorgame/entity-system/wiki).

## Building

To build the entity-system one needs:

- a compiler of choice (`gcc`, `clang`, `MSVC`)
- `cmake`
- [`conan`](https://conan.io)

Simply follow below instructions to get started:

- clone via `git clone https://github.com/inexorgame/entity-system.git`
- `cd entity-system`
- `mkdir build && cd build`
- `conan remote add inexorgame https://api.bintray.com/conan/inexorgame/inexor-conan` (add `inexorgame` remote)
- `conan install .. --build=missing` (installs all dependencies)
- `cmake ..` (builds project files)
- `make` (compiles `entity-system`)

## Documentation

Given you have `doxygen` installed building the docs is easy as pie:

- `cd entity-system`
- `doxygen`
