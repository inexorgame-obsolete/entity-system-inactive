#!/bin/bash

if [ -z $DOCKER_IMAGE ]; then
    # Run with native
    .travis/run_project_build.sh
else
    # Run with docker
    if [[ $DOCKER_IMAGE =~ "gcc" ]]; then
        docker run -e CC=/usr/bin/gcc -e CXX=/usr/bin/g++ -v$(pwd):/home/conan $DOCKER_IMAGE bash -c "pip install conan --upgrade && .travis/run_project_build.sh"
    else
        docker run -v$(pwd):/home/conan $DOCKER_IMAGE bash -c "pip install conan --upgrade && .travis/run_project_build.sh"
    fi
fi