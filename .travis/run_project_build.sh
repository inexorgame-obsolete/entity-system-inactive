#!/bin/bash

rm -rf build && mkdir -p build && cd build
cmake ../
make
./inexor-entity-system-tests

