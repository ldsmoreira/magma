#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>
#include "engine.hpp"

namespace MagmaLib
{
        int Debug::print_vulkan_config()
        {
          VkInstance instance;
          VkInstanceCreateInfo create_info = {};
          create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

          VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
          if (result != VK_SUCCESS) {
            std::cerr << "Failed to create Vulkan instance." << std::endl;
            return 1;
          }

          uint32_t device_count = 0;
          vkEnumeratePhysicalDevices(instance, &device_count, nullptr);
          if (device_count == 0) {
            std::cerr << "No physical devices found that support Vulkan." << std::endl;
            return 1;
          }

          std::vector<VkPhysicalDevice> devices(device_count);
          vkEnumeratePhysicalDevices(instance, &device_count, devices.data());

          std::cout << "Found " << device_count << " physical device(s) that support Vulkan:" << std::endl;
          for (const auto& device : devices) {
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(device, &properties);
            std::cout << " - " << properties.deviceName << std::endl;
          }

          vkDestroyInstance(instance, nullptr);
          return 0;
        };
}