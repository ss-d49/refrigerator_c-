mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=MinSizeRel
mingw32-make
PAUSE