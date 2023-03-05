#include "platform/os/win32/window/win32_window.hpp"

namespace magma {
    
        Win32Window::Win32Window(const WindowProperties& properties) : properties(properties) {
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

        uint32_t Win32Window::getWidth() const {
            return properties.width;
        }

        uint32_t Win32Window::getHeight() const {
            return properties.height;
        }

        bool Win32Window::shouldClose() const {
            glfwSwapBuffers(window);
            return glfwWindowShouldClose(window);
        }

        bool Win32Window::pollEvents() {
            glfwPollEvents();
            return true;
        }

        // void Win32Window::run() {
        //     while (!shouldClose()) {
        //         pollEvents();
        //     }
        // }
    
}