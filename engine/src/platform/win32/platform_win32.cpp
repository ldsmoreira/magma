#include "platform/win32/platform_win32.hpp"
#include "logging/logging.hpp"

namespace magma::platform {
    
    PlatformWin32::PlatformWin32(unsigned short int x, 
                                 unsigned short int y, 
                                 unsigned short int width, 
                                 unsigned short int height, 
                                 const std::string& application_name) : Platform(x, y, width, height, application_name) {
        LOG_INFO("Initializing Win32 platform");
    }

    PlatformWin32::~PlatformWin32() {
    }

    void PlatformWin32::platform_shutdown() {
    }

    bool PlatformWin32::platform_pump_messages(){        
        return true;
    }
}