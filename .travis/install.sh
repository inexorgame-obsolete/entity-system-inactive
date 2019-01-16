#!/bin/bash

set -e
set -x

if [[ "$(uname -s)" == 'Darwin' ]]; then
    brew update || brew update
    brew install cmake --upgrade
    brew install conan --upgrade
fi
