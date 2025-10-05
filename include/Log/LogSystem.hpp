#pragma once
#include "Log.hpp"
#include "Config.hpp"

class LOG_API LogSystem {
private:
    static void SetConfig(const std::string &filePath, const Config &config);
    static void LoadConfig(const std::string& filePath);
public:
    LogSystem() = default;
    static void setConfig(const std::string &filePath, const Config &config);
    static void loadConfig(const std::string& filePath);
    ~LogSystem() = default;
};
#define SETCONFIG(filePath, config) LogSystem::setConfig(filePath, config)
#define LOADCONFIG(filePath) LogSystem::loadConfig(filePath)