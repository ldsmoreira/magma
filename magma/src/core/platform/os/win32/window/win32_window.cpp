#include "platform/os/win32/window/win32_window.hpp"

namespace magma {
    
        Win32Window::Win32Window(const WindowProperties& properties) {
            this->properties = properties;
            initWindow();
        }

        Win32Window::~Win32Window() {
            // Destroy the window and free up any memory used by it
            glfwDestroyWindow(window);
            // Terminate GLFW and free up any memory used by it
            glfwTerminate();
        }
    
        void Win32Window::initWindow() {
            // Initialize GLFW
            glfwInit();

            // Tell GLFW we don't want to use OpenGL
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

            // Tell GLFW we don't want to allow window resizing
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            // Create the window
            window = glfwCreateWindow(properties.width, properties.height, properties.window_name.c_str(), nullptr, nullptr);
        }

        bool Win32Window::shouldClose() const {
            return glfwWindowShouldClose(window);
        }
    
}