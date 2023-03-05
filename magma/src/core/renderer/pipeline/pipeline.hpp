#pragma once

#include <string>
#include <vector>

namespace magma
{
    class Pipeline
    {
    public:
        Pipeline() = default;
        Pipeline(const std::string& vertFilePath, const std::string& fragFilePath);
        ~Pipeline() = default;

    protected:
        static std::vector<char> readFile(const std::string& filePath);
        void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
    };
}