cmake_minimum_required(VERSION 3.10)
project(library)

set(CMAKE_CXX_STANDARD 14)

add_library(algos Lib.h src/Lib.cpp)

install(TARGETS algos DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(FILES Lib.h DESTINATION ${PROJECT_SOURCE_DIR}/include_install)