#include <iostream>
#include "LogConfigReader.h"
#include "FileReader.h"
#include "Log.h"
#include <fstream>
LogConfigReader::LogConfigReader(std::string filePath) {
    configFilePath = std::move(filePath);
    loadConfig();
}

void LogConfigReader::loadConfig() {
    std::fstream fs(configFilePath, std::ios::in);
    if (!fs.is_open()) {
        throw std::runtime_error("Failed to open config file: " + configFilePath);
    }
    Config config;
    fs >> config;
    Log::Instance().setLogLevel(config.getlogLevel());
    Log::Instance().setLogType(config.getlogType());
    Log::Instance().setLogFilePath(config.getlogFilePath());
    Log::Instance().setMaxLogSize(config.getmaxLogSize());
    Log::Instance().setFormat(config.getformat());
    std::cout << config << std::endl;
}

LogConfigReader::~LogConfigReader() = default;
