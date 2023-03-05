#pragma once

#include "window/window.hpp"

#include <GLFW/glfw3.h>

namespace magma {
    
    class Win32Window : public Window {
        public:

            Win32Window(const WindowProperties& properties);
            
            // Implement Window interface
            ~Win32Window();
            
            uint32_t getWidth() const override;
            uint32_t getHeight() const override;

            bool shouldClose() const override;
            bool pollEvents() override;

        private:

            GLFWwindow* window;
            WindowProperties properties;

            void initWindow();
 
    };
}