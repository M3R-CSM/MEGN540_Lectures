# I target a recent cmake, it shouldn't be a problem on a dev machine
cmake_minimum_required(VERSION 3.1)

# Project name
project("MEGN 540 C Refresher")

##########################################################################
# set build type
##########################################################################
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_STANDARD 11)

## Discover C/Cpp files to build
add_executable( examples src/main.c)

add_executable( print_float src/print_float.c )

add_executable( pi_as_hex src/pi_as_hex.c )


