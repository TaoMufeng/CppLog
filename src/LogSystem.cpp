#include "../include/Log/LogSystem.hpp"
#include "../include/Log/Util.hpp"
#include "../include/Log/LogConfigWriter.hpp"
#include "../include/Log/LogConfigReader.hpp"
#include "../include/Log/Log.hpp"

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