#!/bin/bash

rm -rf build && mkdir -p build && cd build
cmake ../
make
cd bin/
./inexor-entity-system-tests

