// Copyright (c) 2023 Andrea Ballestrazzi

#include "server-paths.hpp"
#include "server-patterns.hpp"
#include "server-version.hpp"

#include <drogon/drogon.h>

// C++ STL
#include <filesystem>
#include <string>

namespace rpic_server {

/**
 * @brief Creates the directories that the server will use.
 */
void createServerDirectories() {
    std::filesystem::create_directories(paths::getServerLogPath());
    std::filesystem::create_directories(paths::getServerUploadPath());
}

} // namespace rpic_server

int main(int argc, char* argv[]) {
    // Before proceeding and starting the server, we create the directories
    // that it will use. If the directories don't exist Drogon will throw an error.
    rpic_server::createServerDirectories();

    auto& serverApp{drogon::app()};

    serverApp.loadConfigFile("./server_config.json");

#ifndef _WIN32
    // If we are not on windows, we can run the server as a daemon.
    serverApp.enableRunAsDaemon();
#endif // _WIN32

    // Now we register the health check pattern so that
    // clients can know if the server is running.
    serverApp.registerHandler(std::string{rpic_server::patterns::HEALTH_CHECK_PATH},
                              [](const drogon::HttpRequestPtr& req,
                                 std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
                                  auto resp{drogon::HttpResponse::newHttpResponse()};
                                  resp->setStatusCode(drogon::HttpStatusCode::k200OK);
                                  resp->setBody("OK");
                                  callback(resp);
                              });

    serverApp.run();

    return 0;
}
