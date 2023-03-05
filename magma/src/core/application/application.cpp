#include "application/application.hpp"


namespace magma {
    Application::Application(Window* window, Pipeline pipeline) : window(window), pipeline(pipeline){
        this->window = window;
        this->pipeline = pipeline;
    }


    void Application::run() {
        while (!window->shouldClose()) {
            window->pollEvents();
        }
    }
}