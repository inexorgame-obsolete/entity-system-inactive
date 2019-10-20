#!/bin/bash

conan --version

cp .travis/registry.json ~/.conan/registry.json
ln -s ~/.conan/registry.json ~/.conan/remotes.json
rm -rf build && mkdir -p build && cd build
cmake ../
make
cd bin/
./inexor-tests
./inexor-benchmarks
