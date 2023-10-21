// Copyright (c) 2023 Andrea Ballestrazzi

// C++ STL
#include <iostream>

import RpicServer.ServerVersion;

int main(int argc, char* argv[]) {
    std::cout << rpic_server::version::getServerVersion() << std::endl;
    return 0;
}
