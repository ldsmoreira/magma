#include <iostream>
#include "logging/logging.hpp"
#include "platform/os/win32/window/win32_window.hpp"

using namespace magma;

int main() {

  Logger::init_logger(spdlog::level::level_enum::debug);

  LOG_INFO("Initializing application testbed");

  Win32Window window(WindowProperties("Testbed", 800, 800));

  while (!window.shouldClose()) {
    glfwPollEvents();
  }
  
  return 0;
}