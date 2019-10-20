#!/bin/bash

conan --version

pwd
cp registry.json ~/.conan/registry.json
rm -rf build
conan install . --install-folder build --build=missing
conan build . --build-folder build
cd bin/
./inexor-tests
./inexor-benchmarks
