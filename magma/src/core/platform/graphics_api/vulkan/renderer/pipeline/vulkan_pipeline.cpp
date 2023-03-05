#include "platform/graphics_api/vulkan/renderer/pipeline/vulkan_pipeline.hpp"
#include "logging/logging.hpp"

namespace magma {

    VulkanPipeline::VulkanPipeline(const std::string& vertFilePath, const std::string& fragFilePath) : Pipeline(vertFilePath, fragFilePath){
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }
}