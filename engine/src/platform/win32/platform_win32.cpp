#include "platform/win32/platform_win32.hpp"
#include "logging/logging.hpp"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    LOG_DEBUG("Callback called!");
    switch (message) {
        case WM_CLOSE:
            PostQuitMessage(0);
            LOG_DEBUG("Closing window!");
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            LOG_DEBUG("Destroying window!");
            break;
        case WM_KEYDOWN:
            switch (wParam) {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                    LOG_DEBUG("Escape key pressed!");
                    break;
            }
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

namespace magma::platform {
    
    PlatformWin32::PlatformWin32(unsigned short int x, 
                                 unsigned short int y, 
                                 unsigned short int width, 
                                 unsigned short int height, 
                                 const std::string& application_name) : Platform(x, y, width, height, application_name) {
        
        LOG_DEBUG("Initializing Win32 platform");

        this->state = new platform_state;
        this->state->internal_state = new internal_state;
        internal_state* state = static_cast<struct internal_state*>(this->state->internal_state);

        state->h_instance = GetModuleHandleA(nullptr);

        // Setup and register window class
        WNDCLASS window_class = {};

        window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        window_class.lpfnWndProc = DefWindowProcA;
        window_class.hInstance = state->h_instance;
        window_class.hIcon = LoadIconA(0, IDI_APPLICATION);
        window_class.hCursor = LoadCursorA(0, IDC_ARROW);
        window_class.lpszClassName = application_name.c_str();
        window_class.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
        window_class.lpszMenuName = 0;
        window_class.cbClsExtra = 0;
        window_class.cbWndExtra = 0;
        window_class.lpfnWndProc = WindowProc;

        RegisterClass(&window_class);

        // Obtain the size of the border of the window
        RECT window_rect = {0, 0, width, height};
        AdjustWindowRectEx(&window_rect, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, false, 0);

        // Get the size of the border of the window
        width = window_rect.right - window_rect.left;
        height = window_rect.bottom - window_rect.top;

        // Create the window style
        DWORD window_style = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

        // Create window
        state->h_wnd = CreateWindowExA(0, 
                                       application_name.c_str(), 
                                       application_name.c_str(), 
                                       window_style, 
                                       x, 
                                       y, 
                                       width, 
                                       height, 
                                       0, 
                                       0, 
                                       state->h_instance, 
                                       0);

        if (!state->h_wnd) {
            LOG_ERROR("Failed to create window");
        }

        // Show the window
        ShowWindow(state->h_wnd, SW_SHOW);
        SetForegroundWindow(state->h_wnd);
        SetFocus(state->h_wnd);

        // Setup pixel format
        PIXELFORMATDESCRIPTOR pixel_format_descriptor = {};
        pixel_format_descriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pixel_format_descriptor.nVersion = 1;
        pixel_format_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pixel_format_descriptor.iPixelType = PFD_TYPE_RGBA;
        pixel_format_descriptor.cColorBits = 32;
        pixel_format_descriptor.cDepthBits = 24;
        pixel_format_descriptor.cStencilBits = 8;
        pixel_format_descriptor.iLayerType = PFD_MAIN_PLANE;

        // Get the device context
        state->h_dc = GetDC(state->h_wnd);
    }

    PlatformWin32::~PlatformWin32() {
        delete this->state;
    }

    void PlatformWin32::platform_shutdown() {
    }

    bool PlatformWin32::platform_pump_messages(){        
        // Run message loop
        MSG msg = {};
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {

            if (msg.message == WM_QUIT) {
                LOG_DEBUG("Received WM_QUIT message");
                return false;
            }else{
                // TODO: Remove this debug code or change it to be optimal
                // Get the name of the message
                char message_name[256];
                if (GetClipboardFormatNameA(msg.message, message_name, sizeof(message_name))) {
                    LOG_DEBUG("Received message: %s", message_name);
                } else {
                    LOG_DEBUG("Received message with ID: %d", msg.message);
                }
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);

        }

        return true;
    }
}