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
file(GLOB SRC_FILES "src/*.c" "src/*.cpp") # Load all files in src folder

add_executable( megn540_c_refresher ${SRC_FILES})

