#include "logging/logging.hpp"
#include "renderer/pipeline/pipeline.hpp"

namespace magma {
    class VulkanPipeline : public Pipeline {
    public:
        VulkanPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
        virtual ~VulkanPipeline() = default;
    };
}