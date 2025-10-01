#pragma once

#include <string>
#include "Config.h"

class LogConfigWriter {
    std::string configFilePath;
public:
    LogConfigWriter(std::string filePath);
    void write(const Config& config);
    ~LogConfigWriter() = default;
};
