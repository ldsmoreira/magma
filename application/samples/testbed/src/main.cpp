#include <iostream>
#include "logging/logging.hpp"
#include "platform/os/win32/window/win32_window.hpp"
#include "application/application.hpp"

using namespace magma;

int main() {

  Logger::init_logger(spdlog::level::level_enum::debug);

  LOG_INFO("Initializing application testbed");

  Win32Window window(WindowProperties("Testbed", 800, 800));

  // NOTE: behavior when we build magma as a dll and we try to handle the event loop in the main thread
  // For some reason that we need to discover later is that the
  // event loop for the window needs to be in the dll and not in
  // the main thread.
  // window.run();

  Application app(&window, Pipeline("magma/src/core/platform/graphics_api/vulkan/shader/shaders/simple_shader/simple_shader.vert.spv",
                                    "magma/src/core/platform/graphics_api/vulkan/shader/shaders/simple_shader/simple_shader.frag.spv"));

  app.run();
  
  return 0;
}