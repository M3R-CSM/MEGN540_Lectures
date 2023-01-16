# I target a recent cmake, it shouldn't be a problem on a dev machine
cmake_minimum_required(VERSION 3.1)

# Project name
project("MEGN 540 Embedded C")

##########################################################################
# set build type
##########################################################################
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_STANDARD 11)

add_executable( example src/example.c)

# specify header file search folder
include_directories(include)

add_executable( bit_operations src/bit_operations.c)

