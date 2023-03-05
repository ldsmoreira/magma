#pragma once

#include <string>

namespace magma {

    struct WindowProperties {
        std::string window_name;
        uint32_t width;
        uint32_t height;

        WindowProperties(const std::string& window_name = "Magma",
                         uint32_t width = 1280,
                         uint32_t height = 720)
            : window_name(window_name), width(width), height(height) {}
    };

    class Window {
    public:
        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;

        virtual bool shouldClose() const = 0;
        virtual bool pollEvents() = 0;
    };
}