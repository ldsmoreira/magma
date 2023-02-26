#pragma once

#include "platform/platform.hpp"

#include <Windows.h>
#include <Windowsx.h>

typedef struct internal_state {
    // Instance of the application
    HINSTANCE h_instance;
    
    // Handle to the window
    HWND h_wnd;
    
    // Handle to the device context
    HDC h_dc;
    
    // Handle to the rendering context
    HGLRC h_rc;
    
    // Flag to indicate if the application is running
    bool running;
} internal_state;

namespace magma::platform {

    class PlatformWin32 : public Platform {
    public:
        // Constructor
        PlatformWin32(unsigned short int x, 
                      unsigned short int y, 
                      unsigned short int width, 
                      unsigned short int height, 
                      const std::string& application_name);

        // Destructor
        ~PlatformWin32();

        void platform_shutdown() override;
        bool platform_pump_messages() override;
    };

};
