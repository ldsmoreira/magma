#include <iostream>
#include "core/logging/logging.hpp"


using namespace magma;

int main() {
  Logger::init_logger(spdlog::level::level_enum::debug);

  LOG_INFO("Initializing application testbed");
  
  return 0;
}