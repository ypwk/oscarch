#!/bin/bash -x

#create directory
mkdir -p build-linux

#go to directory
cd build-linux

#cmake will check if the compiler, C++ libraries, etc. are correct in your system and generate the necesary files to compile the code
cmake ../

#cmake will compile the code and build the executable
cmake --build ./

#we run the program now:
./nextdate_exec 02/21/1997
