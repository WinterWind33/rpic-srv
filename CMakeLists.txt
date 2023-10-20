# Copyright (c) 2023 Andrea Ballestrazzi
cmake_minimum_required(VERSION 3.27.7)

set(CMAKE_CXX_STANDARD 23)

project(rpic_server VERSION 0.1.0 LANGUAGES CXX)

###########################
# Rpic Server Executable
###########################

set (RPI_SERVER_SRC
    src/entry-point.cpp
)

add_executable(rpic_server ${RPI_SERVER_SRC})
set_target_properties(rpic_server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
