#pragma once

#include "core/window/window.hpp"
#include <GLFW/glfw3.h>

namespace magma {
    
    class Win32Window : public Window {
        public:
            Win32Window(const WindowProperties& properties);
            ~Win32Window() = default;

            uint32_t getWidth() const override { return m_data.width; }
            uint32_t getHeight() const override { return m_data.height; }

        private:
            WindowProperties properties;
        
    }
}