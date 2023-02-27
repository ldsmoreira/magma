#include <iostream>
#include "logging/logging.hpp"
#include "platform/win32/platform_win32.hpp"

using namespace magma;

int main() {
  logging::Logger::init_logger(spdlog::level::level_enum::debug);

  platform::PlatformWin32 platform(0, 0, 800, 800, "Magma");

  while(true){
    if(!platform.platform_pump_messages()){
      break;
    }
  }

  LOG_INFO("Exiting with code %d", 0);
  
  return 0;
}