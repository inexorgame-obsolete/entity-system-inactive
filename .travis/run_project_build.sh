#!/bin/bash

conan --version

cp .travis/registry.json ~/.conan/registry.json
ln -s ~/.conan/registry.json ~/.conan/remotes.json
rm -rf build
conan install . --install-folder ./build --build=missing
conan build . --build-folder ./build
cd bin/
./inexor-tests
./inexor-benchmarks
