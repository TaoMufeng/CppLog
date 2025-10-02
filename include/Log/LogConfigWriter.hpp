#pragma once

#include <string>
#include "Config.hpp"

class LogConfigWriter {
    std::string configFilePath;
public:
    LogConfigWriter(std::string filePath);
    void write(const Config& config);
    ~LogConfigWriter() = default;
};
