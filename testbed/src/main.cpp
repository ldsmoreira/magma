#include <iostream>
#include "logging/logging.hpp"
#include "platform/win32/platform_win32.hpp"

using namespace magma;

int main() {
  logging::Logger::init_logger(spdlog::level::level_enum::debug);

  LOG_INFO("Info %s message %d", "test", 1);
  LOG_WARN("Warn message %d", 2);
  LOG_ERROR("Error message %d", 3);
  LOG_CRITICAL("Critical message %d", 4);
  LOG_DEBUG("Debug message %d", 5);

  platform::PlatformWin32 platform(0, 0, 800, 600, "Magma");
  
  return 0;
}