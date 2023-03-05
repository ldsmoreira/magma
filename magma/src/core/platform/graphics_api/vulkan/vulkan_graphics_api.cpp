#include "platform/graphics_api/vulkan/vulkan_graphics_api.hpp"

namespace magma {
    VulkanGraphicsAPI::VulkanGraphicsAPI() {
    }

    void VulkanGraphicsAPI::initialize() {
        createInstance();
    }

    void VulkanGraphicsAPI::shutdown() {

    }

    void VulkanGraphicsAPI::createInstance() {
        // Create an instance of the Vulkan API
        VkInstance instance;

        // Specify the application info
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Magma";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Magma";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        // Specify the instance info
        VkInstanceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        // Create the Vulkan instance
        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance!");
        }
    }
}