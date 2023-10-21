// Copyright (c) 2023 Andrea Ballestrazzi

// C++ STL
#include <iostream>

#include "server-version.hpp"

int main(int argc, char* argv[]) {
    std::cout << rpic_server::version::getServerVersion() << std::endl;
    return 0;
}
