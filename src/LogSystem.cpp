//
// Created by 吉秋羽 on 2025/10/1.
//

#include "../include/Log/LogSystem.h"
#include "../include/Log/Util.h"
#include "../include/Log/LogConfigWriter.h"
#include "../include/Log/LogConfigReader.h"
#include "../include/Log/Log.h"

void LogSystem::SetConfig(const std::string &filePath, const Config &config) {
    LogConfigWriter configWriter(filePath);
    Config config_ = config;
    config_.setlogLevel(Util::toLower(config_.getlogLevel()));
    config_.setlogType(Util::toLower(config_.getlogType()));
    configWriter.write(config_);
}
void LogSystem::LoadConfig(const std::string &filePath) {
    LogConfigReader configReader(filePath);
}
void LogSystem::setConfig(const std::string &filePath, const Config &config) {
    SetConfig(filePath, config);
}
void LogSystem::loadConfig(const std::string &filePath) {
    LoadConfig(filePath);
}