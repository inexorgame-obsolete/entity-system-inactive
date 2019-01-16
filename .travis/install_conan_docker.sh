#!/bin/bash

set -e
set -x

sudo apt-get -qq update
sudo apt-get install -y python3-pip python3-setuptools

pip3 install conan --upgrade

