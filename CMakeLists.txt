# Copyright (c) 2023 Andrea Ballestrazzi
cmake_minimum_required(VERSION 3.27.7)

set(CMAKE_CXX_STANDARD 23)

project(rpic_server VERSION 0.1.0 LANGUAGES CXX)

###########################
# External dependencies
###########################
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(Drogon CONFIG REQUIRED)
find_path(NEARGYE_SEMVER_INCLUDE_DIRS "neargye/semver.hpp")

###########################
# Version generation
###########################
set(RPIC_SERVER_VERSION_MAJOR 0)
set(RPIC_SERVER_VERSION_MINOR 1)
set(RPIC_SERVER_VERSION_PATCH 0)
set(RPIC_SERVER_VERSION_PRERELEASE "alpha")
set(RPIC_SERVER_VERSION "${RPIC_SERVER_VERSION_MAJOR}.${RPIC_SERVER_VERSION_MINOR}.${RPIC_SERVER_VERSION_PATCH}")
set(RPIC_GENERATED_FILES_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")

configure_file(src/server-version.ixx.in ${RPIC_GENERATED_FILES_DIR}/server-version.ixx)

###########################
# Rpic Server Executable
###########################
add_executable(rpic_server "src/entry-point.cpp" ${RPIC_GENERATED_FILES_DIR}/server-version.ixx)
target_link_libraries(rpic_server PRIVATE Microsoft.GSL::GSL Drogon::Drogon)
set_target_properties(rpic_server PROPERTIES
    VERSION ${RPIC_SERVER_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

target_include_directories(rpic_server PRIVATE ${NEARGYE_SEMVER_INCLUDE_DIRS} ${RPIC_GENERATED_FILES_DIR})
