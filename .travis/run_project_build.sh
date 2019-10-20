#!/bin/bash

conan --version

pwd
ls -lah .travis/registry.json
echo ".travis/registry.json"
cat .travis/registry.json
echo "~/.conan/registry.json"
cat ~/.conan/registry.json
echo "~/.conan/remotes.json"
cat ~/.conan/remotes.json
ln -s ~/.conan/registry.json ~/.conan/remotes.json
# cp .travis/registry.json ~/.conan/registry.json
rm -rf build
conan install . --install-folder build --build=missing
conan build . --build-folder build
cd bin/
./inexor-tests
./inexor-benchmarks
