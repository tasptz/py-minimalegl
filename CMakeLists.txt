cmake_minimum_required(VERSION 3.13)
project(minimalegl)

set(CMAKE_CXX_STANDARD 11)

option(WITH_PYTHON "Activate python wrapper")
if(WITH_PYTHON)
    add_subdirectory("${CMAKE_SOURCE_DIR}/pybind11")
endif()

add_subdirectory(cpp)
