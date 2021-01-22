#!/bin/bash -x

#create the build directory
mkdir -p build

#go to the directory
cd build

#cmake will check if the compiler, C++ libraries, etc. are correct in your system and generate the necessary files to compile the code
cmake ../

#cmake will compile the code and build the executable
cmake --build ./

#we run the program now
./cpp_oo_intro argument_test
