#pragma once

#include <string>
#include <memory>


namespace magma::platform {

    typedef struct platform_state{
        void* internal_state;
    } platform_state;

    class Platform {
    public:
        // Dimensions of the screen
        unsigned short int x;
        unsigned short int y;
        unsigned short int width;
        unsigned short int height;
        
        // Name of the application
        const std::string application_name;

        // State of the platform
        platform_state* state;

        // Constructor
        Platform(unsigned short int x, 
                 unsigned short int y, 
                 unsigned short int width, 
                 unsigned short int height, 
                 const std::string& application_name){};

        // Destructor
        ~Platform() = default;

        virtual void platform_shutdown(){};
        virtual bool platform_pump_messages(){ return false;};
    };

};