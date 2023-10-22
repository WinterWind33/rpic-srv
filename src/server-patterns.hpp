// Copyright (c) 2023 Andrea Ballestrazzi
#pragma once

// C++ STL
#include <string_view>

namespace rpic_server::patterns {

/**
 * @brief The pattern for the server health check.
 */
constexpr std::string_view HEALTH_CHECK_PATH{"/health-check"};

} // namespace rpic_server::patterns
