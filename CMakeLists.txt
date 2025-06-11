cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(AnimDX12 LANGUAGES CXX)

add_definitions(-D_UNICODE)
add_definitions(-DUNICODE)

include(cmake/OutputDirectories.cmake)
include(cmake/CopyFilesToBinary.cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

set(FBXSDK_LIB_DIR ${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/lib)

if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
    message(WARNING "The Binary directory of CMake cannot be the same as source directory!")
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if (WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

add_subdirectory(Common)
add_subdirectory(SkeletonStructure)

copy_all_files_to_build(${FBXSDK_LIB_DIR})