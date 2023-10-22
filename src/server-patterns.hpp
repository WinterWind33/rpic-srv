// Copyright (c) 2023 Andrea Ballestrazzi
#pragma once

// C++ STL
#include <string_view>

namespace rpic_server::patterns {

/**
 * @brief The pattern for the server health check.
 */
constexpr std::string_view HEALTH_CHECK_PATH{"/health-check"};

/**
 * @brief The patter used to retrieve the server information.
 */
constexpr std::string_view SERVER_INFO_PATH{"/server-info"};

} // namespace rpic_server::patterns
