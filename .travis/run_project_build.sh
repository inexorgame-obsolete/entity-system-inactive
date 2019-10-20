#!/bin/bash

conan --version

cp .travis/registry.json ~/.conan/registry.json
ln -s ~/.conan/registry.json ~/.conan/remotes.json
rm -rf build && mkdir -p build && cd build
cmake ../
make
cd bin/
#rm -rf build
#conan install . --install-folder ./build --build=missing
#conan build . --build-folder ./build
#cd build/bin/
./inexor-tests
./inexor-benchmarks
