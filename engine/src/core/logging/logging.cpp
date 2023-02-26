#include "logging.hpp"

namespace magma::logging {

    void Logger::init_logger(spdlog::level::level_enum level) {
                // TODO: Add file logging
                // TODO: Add aligment
                spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
                spdlog::set_level(level);
    }

    void Logger::info(std::string message, ...) {
        va_list args;
        va_start(args, message);
        spdlog::info(format_message(message, args));
        va_end(args);
    }

    void Logger::warn(std::string message, ...) {
        va_list args;
        va_start(args, message);
        spdlog::warn(format_message(message, args));
        va_end(args);
    }

    void Logger::error(std::string message, ...) {
        va_list args;
        va_start(args, message);
        spdlog::error(format_message(message, args));
        va_end(args);
    }

    void Logger::critical(std::string message, ...) {
        va_list args;
        va_start(args, message);
        spdlog::critical(format_message(message, args));
        va_end(args);
    }

    void Logger::debug(std::string message, ...) {
        va_list args;
        va_start(args, message);
        spdlog::debug(format_message(message, args));
        va_end(args);
    }

    std::string Logger::format_message(std::string message, va_list args) {
        // Format message with the list of arguments
        // Copy the variable argument list to another variable argument list
        va_list args_copy;
        va_copy(args_copy, args);
        // Determine the size of the buffer needed to hold the formatted string
        size_t size = std::vsnprintf(nullptr, 0, message.c_str(), args_copy) + 1;
        // Free the resources used by the copied variable argument list
        va_end(args_copy);
        // Create a buffer to hold the formatted string
        std::unique_ptr<char[]> buf(new char[size]);
        // Format the message string into the buffer
        std::vsnprintf(buf.get(), size, message.c_str(), args);
        // Create a string object from the buffer
        return std::string(buf.get(), buf.get() + size - 1);
    }
}