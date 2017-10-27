cmake_minimum_required(VERSION 2.8)
project(jalb)

include_directories(include)
include(jalb.h)

set(JALB_SOURCES
    jalb.cpp
	src/Scene.cpp 
    src/Node.cpp
    src/Label.cpp
    src/Director.cpp
    src/Pos.cpp
    src/Size.cpp
    src/Utils.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wall")

add_library(jalb ${JALB_SOURCES})
add_executable(main ${JALB_SOURCES})

set_property(TARGET jalb PROPERTY CXX_STANDARD 14)
set_property(TARGET jalb PROPERTY CXX_STANDARD_REQUIRED ON)

set_property(TARGET main PROPERTY CXX_STANDARD 14)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)
