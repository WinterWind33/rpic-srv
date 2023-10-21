// Copyright (c) 2023 Andrea Ballestrazzi

#include <iostream>
#include <neargye/semver.hpp>

#include "server-version.hpp"

int main(int argc, char* argv[]) {
    std::cout << rpic_server::version::getServerVersion() << std::endl;
    return 0;
}
