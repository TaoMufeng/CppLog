//
// Created by 吉秋羽 on 2025/10/1.
//

#include "../include/Log/LogConfigWriter.hpp"
#include "../include/Log/FileWriter.hpp"
void LogConfigWriter::write(const Config &config) {
    FileWriter<Config> fileWriter(configFilePath);
    fileWriter.write(config);
}

LogConfigWriter::LogConfigWriter(std::string filePath) {
    configFilePath = std::move(filePath);
}
