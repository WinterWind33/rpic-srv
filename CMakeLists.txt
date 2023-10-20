# Copyright (c) 2023 Andrea Ballestrazzi
cmake_minimum_required(VERSION 3.27.7)

set(CMAKE_CXX_STANDARD 23)

project(rpic_server VERSION 0.1.0 LANGUAGES CXX)

###########################
# External dependencies
###########################
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_path(NEARGYE_SEMVER_INCLUDE_DIRS "neargye/semver.hpp")

###########################
# Rpic Server Executable
###########################

add_executable(rpic_server "src/entry-point.cpp")
target_include_directories(rpic_server PRIVATE ${NEARGYE_SEMVER_INCLUDE_DIRS} Microsoft.GSL::GSL)
set_target_properties(rpic_server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
