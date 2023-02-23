#include "logging.hpp"

namespace magma::logging {

    void Logger::init_logger(spdlog::level::level_enum level) {
                // TODO: Add file logging
                // TODO: Add aligment
                spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
                spdlog::set_level(level);
    }

    void Logger::info(std::string message) {
        spdlog::info(message);
    }

    void Logger::warn(std::string message) {
        spdlog::warn(message);
    }

    void Logger::error(std::string message) {
        spdlog::error(message);
    }

    void Logger::critical(std::string message) {
        spdlog::critical(message);
    }

    void Logger::debug(std::string message) {
        spdlog::debug(message);
    }
}