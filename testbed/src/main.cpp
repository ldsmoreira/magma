#include "engine.hpp"
#include <iostream>
#include "logging/logging.hpp"

using namespace magma;

int main() {
  logging::Logger::init_logger(spdlog::level::level_enum::debug);

  LOG_INFO("Info %s message %d", "test", 1);
  LOG_WARN("Warn message %d", 2);
  LOG_ERROR("Error message %d", 3);
  LOG_CRITICAL("Critical message %d", 4);
  LOG_DEBUG("Debug message %d", 5);

  MagmaLib::Debug::print_vulkan_config();

  return 0;
}