building
--------

Given you have `git`, `cmake` and your favourite compiler toolchain installed, proceed as follows

- `git submodule update --init`
- `cd dependencies/crossguid && mkdir build && cd build && cmake .. && make`
- `cd ../../`
- `mkdir -p build && cd build && cmake .. && make`

This document is subject to change once `conan` config has been integrated!


