#!/bin/bash -x

#create directory
mkdir -p build-unix

#go to directory
cd build-unix

#cmake will check if the compiler, C++ libraries, etc. are correct in your system and generate the necesary files to compile the code
cmake ../

#cmake will compile the code and build the executable
cmake --build ./

#we run the program now:
./trees_exec
