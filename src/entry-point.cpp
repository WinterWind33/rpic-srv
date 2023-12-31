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

    // When the user sends a health-check request we must send the health-check.html file
    // back.
    serverApp.registerHandler(
        std::string{rpic_server::patterns::HEALTH_CHECK_PATH},
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            auto resp{drogon::HttpResponse::newRedirectionResponse("/health-check.html")};

            callback(resp);
        });

    // We register the info pattern so that clients can know
    // the version of the server.
    serverApp.registerHandler(
        std::string{rpic_server::patterns::SERVER_INFO_PATH},
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            auto resp{drogon::HttpResponse::newHttpResponse()};
            resp->setStatusCode(drogon::HttpStatusCode::k200OK);

            resp->setContentTypeCode(drogon::CT_APPLICATION_JSON);
            resp->setBody("{\"server_version\": \"" +
                          rpic_server::version::getServerVersion().to_string() + "\"}");

            callback(resp);
        });

    serverApp.run();

    return 0;
}
