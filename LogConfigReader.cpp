#include <iostream>
#include "LogConfigReader.h"
#include "FileReader.h"
#include "Log.h"
LogConfigReader::LogConfigReader(std::string filePath) {
    configFilePath = std::move(filePath);
    loadConfig();
}

void LogConfigReader::loadConfig() {
    // 读取配置文件的逻辑
    // 例如，解析日志级别、输出格式等
    FileReader fileReader(configFilePath);
    Log::Instance().setLogType(fileReader.read("log_type"));
    Log::Instance().setLogLevel(fileReader.read("log_level"));
    Log::Instance().setLogFilePath(fileReader.read("log_file_path"));
    Log::Instance().setMaxLogSize(fileReader.read("max_log_size"));
    Log::Instance().setFormat(fileReader.read("format"));
}

LogConfigReader::~LogConfigReader() = default;
