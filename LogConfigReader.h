#pragma once

#include <string>

class LogConfigReader {
private:
    std::string configFilePath;
    void loadConfig();
public:
    explicit LogConfigReader(std::string filePath);
    ~LogConfigReader();
};
