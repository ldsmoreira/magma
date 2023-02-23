#include "engine.hpp"
#include <iostream>
#include "logging/logging.hpp"

using namespace magma;

int main() {
  logging::Logger::init_logger(spdlog::level::level_enum::debug);

  logging::Logger::info("Info message");
  logging::Logger::warn("Warn message");
  logging::Logger::error("Error message");
  logging::Logger::critical("Critical message");
  logging::Logger::debug("Debug message");

  MagmaLib::Debug::print_vulkan_config();

  return 0;
}