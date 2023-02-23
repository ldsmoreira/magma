#pragma once
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace magma::logging {
    class Logger {
        public:

            static void init_logger(spdlog::level::level_enum level = spdlog::level::info);

            static void info(std::string message);
            static void warn(std::string message);
            static void error(std::string message);
            static void critical(std::string message);
            static void debug(std::string message);
    };
}