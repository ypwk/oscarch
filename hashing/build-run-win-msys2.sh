#!/bin/bash -x

#IMPORTANT: this script must be executed on the "MSYS2 MinGW" terminal (as opposed to the Windows terminal)

#create directory
mkdir -p build-win-msys2

#go to directory
cd build-win-msys2

#cmake will check if the compiler, C++ libraries, etc. are correct in your system and generate the necessary files to compile the code
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_C_COMPILER=gcc.exe -DCMAKE_CXX_COMPILER=g++.exe -G "CodeBlocks - MinGW Makefiles" ../

#cmake will compile the code and build the executable
cmake --build ./

#we run the program now:
./hashing.exe ../addresses.txt
