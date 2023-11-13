#!/bin/bash
set -ex
cmake -B build -S . -G "Ninja" -DCMAKE_INSTALL_PREFIX=bin -DCMAKE_BUILD_TYPE=Release
cmake --build build -j`nproc` --target install
rm -rf build
