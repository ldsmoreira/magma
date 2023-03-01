#pragma once

#include <string>


namespace magma {

    struct WindowProperties {
        std::string title;
        uint32_t width;
        uint32_t height;

        WindowProperties(const std::string& title = "Magma",
                         uint32_t width = 1280,
                         uint32_t height = 720)
            : title(title), width(width), height(height) {}
    };

    class Window {
    public:
        virtual ~Window() = default;

        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;
    };
}