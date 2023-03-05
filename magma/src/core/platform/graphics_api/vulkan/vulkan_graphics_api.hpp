#include "graphics_api/graphics_api.hpp"
#include <vulkan/vulkan.h>
#include <stdexcept>

namespace magma
{
    class VulkanGraphicsAPI : public GraphicsAPI
    {
    public:
        VulkanGraphicsAPI();
        ~VulkanGraphicsAPI() override = default;
        void initialize() override;
        void shutdown() override;

    private:
        VkInstance instance;
        void createInstance();
    };
}