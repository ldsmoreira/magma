#pragma once

#include "window/window.hpp"
#include "renderer/pipeline/pipeline.hpp"

namespace magma {
    class Application {
    public:
        Application(Window* window, Pipeline pipeline);
        ~Application() = default;

        void run();

    private:
        Window* window;
        Pipeline pipeline;
    };
}