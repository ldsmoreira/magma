#pragma once

#include "window/window.hpp"

#include <GLFW/glfw3.h>

namespace magma {
    
    class Win32Window : public Window {
        public:

            Win32Window(const WindowProperties& properties);
            
            // Implement Window interface
            ~Win32Window();
            uint32_t getWidth() const override { return properties.width; }
            uint32_t getHeight() const override { return properties.height; }

            bool shouldClose() const;

        private:

            GLFWwindow* window;
            WindowProperties properties;

            void initWindow();
 
    };
}