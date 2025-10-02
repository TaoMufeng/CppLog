#pragma once

#include <string>
#include "Config.hpp"

class LogConfigReader {
private:
    std::string configFilePath;
    void loadConfig();
public:
    explicit LogConfigReader(std::string filePath);
    ~LogConfigReader();
};
