// Copyright (c) 2023 Andrea Ballestrazzi
#pragma once

// C++ STL
#include <filesystem>
#include <string_view>

namespace rpic_server::paths {

/**
 * @brief Get the path of the log directory that the server will use.
 *
 * @return The path of the log directory that the server will use.
 */
[[nodiscard]] inline std::filesystem::path getServerLogPath() noexcept {
    constexpr std::string_view logDirName{"logs"};
    return std::filesystem::path{logDirName};
}

/**
 * @brief Get the path of the upload directory that the server will use.
 *
 * @return The path of the upload directory that the server will use.
 */
[[nodiscard]] inline std::filesystem::path getServerUploadPath() noexcept {
    constexpr std::string_view uploadDirName{"uploads"};
    return std::filesystem::path{uploadDirName};
}

} // namespace rpic_server::paths
