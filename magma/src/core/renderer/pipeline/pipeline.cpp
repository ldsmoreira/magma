#include "renderer/pipeline/pipeline.hpp"
#include "logging/logging.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace magma {

    Pipeline::Pipeline(const std::string& vertFilePath, const std::string& fragFilePath) {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    std::vector<char> Pipeline::readFile(const std::string& filePath){
        // Open the file in binary mode at the end of the file
        // std::ios::ate means that the read/write position of the file pointer will be set to the end of the file
        // std::ios::binary means that the file will be read/written in binary mode
        std::ifstream file(filePath, std::ios::ate | std::ios::binary);

        // Check that the file was successfully opened
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        // Get the size of the file
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        // Move to the beginning of the file
        file.seekg(0);
        // Read the file into the buffer
        file.read(buffer.data(), fileSize);

        // Close the file
        file.close();

        // Return the buffer
        return buffer;
    }

    void Pipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath){
        // Read the vertex shader file
        std::vector<char> vertShaderCode = readFile(vertFilePath);
        // Read the fragment shader file
        std::vector<char> fragShaderCode = readFile(fragFilePath);

        LOG_INFO("Vertex shader code size: %d", vertShaderCode.size());
        LOG_INFO("Fragment shader code size: %d", fragShaderCode.size());
    }
}