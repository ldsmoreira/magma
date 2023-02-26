#pragma once
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define LOG_INFO(message, ...) magma::logging::Logger::info(message, ##__VA_ARGS__)
#define LOG_WARN(message, ...) magma::logging::Logger::warn(message, ##__VA_ARGS__)
#define LOG_ERROR(message, ...) magma::logging::Logger::error(message, ##__VA_ARGS__)
#define LOG_CRITICAL(message, ...) magma::logging::Logger::critical(message, ##__VA_ARGS__)
#define LOG_DEBUG(message, ...) magma::logging::Logger::debug(message, ##__VA_ARGS__)

// TODO: Add ifdef and debug levels to not compile based on the level

namespace magma::logging {
    class Logger {
        public:

            static void init_logger(spdlog::level::level_enum level = spdlog::level::info);

            static void info(std::string message, ...);
            static void warn(std::string message, ...);
            static void error(std::string message, ...);
            static void critical(std::string message, ...);
            static void debug(std::string message, ...);

        private:
            static std::string format_message(std::string message, va_list args);
    };
}