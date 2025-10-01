#pragma once

#include <string>
#include "Config.h"

class LogConfigReader {
private:
    std::string configFilePath;
    void loadConfig();
public:
    explicit LogConfigReader(std::string filePath);
    ~LogConfigReader();
};
