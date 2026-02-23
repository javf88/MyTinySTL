#*******************************************************************************
# Project config
#*******************************************************************************/

cmake_minimum_required(VERSION 3.10)

project(MyTinySTL
    LANGUAGES CXX
    VERSION 2.0.1 # it was foraked at 2.0.0, 2.0.1 is buildsystem withour breaking APIs
    DESCRIPTION "A tiny stl library for C++17")

message(STATUS "Configuring ${PROJECT_NAME} v${PROJECT_VERSION}")

# build type
#set(CMAKE_BUILD_TYPE release)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-sign-compare -Wno-unused-but-set-variable -Wno-array-bounds")
    # set(EXTRA_CXX_FLAGS -Weffc++ -Wswitch-default -Wfloat-equal -Wconversion -Wsign-conversion)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5.0.0")
        message(FATAL_ERROR "required GCC 5.0 or later")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-sign-compare")
    # set(EXTRA_CXX_FLAGS -Weffc++ -Wswitch-default -Wfloat-equal -Wconversion -Wimplicit-fallthrough)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.5.0")
        message(FATAL_ERROR "required Clang 3.5 or later")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    endif()
endif()

message(STATUS "The cmake_cxx_flags is: ${CMAKE_CXX_FLAGS}")
#*******************************************************************************
# CMake Submodules
#*******************************************************************************

# include(GoogleTest) is not working
find_package(GTest REQUIRED)

#*******************************************************************************
# Implementation
#*******************************************************************************

add_subdirectory(src)

#*******************************************************************************
# Testing
#*******************************************************************************

add_subdirectory(tests)
