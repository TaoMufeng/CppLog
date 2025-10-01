//
// Created by 吉秋羽 on 2025/10/1.
//

#include "../include/Log/LogConfigWriter.h"

void LogConfigWriter::write(const Config &config) {
    std::ofstream ofs(configFilePath);
    if (!ofs.is_open()) {
        throw std::runtime_error("Failed to open config file: " + configFilePath);
    }
    ofs << config;
}

LogConfigWriter::LogConfigWriter(std::string filePath) {
    configFilePath = std::move(filePath);
}
