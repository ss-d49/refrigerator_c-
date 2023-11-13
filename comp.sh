#!/bin/bash
set -ex
conan install . --deployer-folder build -of build --build missing
cmake -B build -S . -G "Ninja" -DCMAKE_INSTALL_PREFIX=bin -DCMAKE_BUILD_TYPE=Release --preset conan-release
cmake --build build -j`nproc` --target install
rm -rf build CMakeUserPresets.json
