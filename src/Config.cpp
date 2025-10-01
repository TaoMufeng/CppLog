//
// Created by 吉秋羽 on 2025/10/1.
//

#include "../include/Log/Config.h"

std::ostream& operator<<(std::ostream& os, const Config& config) {
    os << "logLevel: " << config.logLevel << std::endl;
    os << "logType: " << config.logType << std::endl;
    os << "logFilePath: " << config.logFilePath << std::endl;
    os << "maxLogSize: " << config.maxLogSize << std::endl;
    os << "format: " << config.format << std::endl;
    return os;
}
std::istream & operator>>(std::istream& ifs, Config& config) {
    std::string line;
    std::getline(ifs, config.logLevel);
    std::getline(ifs, config.logType);
    std::getline(ifs, config.logFilePath);
    std::getline(ifs, config.maxLogSize);
    std::getline(ifs, config.format);
    return ifs;
}
std::ofstream& operator<<(std::ofstream& ofs, const Config& config) {
    ofs << config.logLevel << std::endl;
    ofs << config.logType << std::endl;
    ofs << config.logFilePath << std::endl;
    ofs << config.maxLogSize << std::endl;
    ofs << config.format << std::endl;
    return ofs;
}
std::ifstream & operator>>(std::ifstream& ifs, Config& config) {
    std::string line;
    std::getline(ifs, config.logLevel);
    std::getline(ifs, config.logType);
    std::getline(ifs, config.logFilePath);
    std::getline(ifs, config.maxLogSize);
    std::getline(ifs, config.format);
    return ifs;
}

std::string Config::GetlogLevel() const {
    return logLevel;
}

std::string Config::getlogLevel() const {
    return GetlogLevel();
}

std::string Config::GetlogType() const {
    return logType;
}
std::string Config::getlogType() const {
    return GetlogType();
}
std::string Config::GetlogFilePath() const {
    return logFilePath;
}
std::string Config::getlogFilePath() const {
    return GetlogFilePath();
}

std::string Config::GetmaxLogSize() const {
    return maxLogSize;
}
std::string Config::getmaxLogSize() const {
    return GetmaxLogSize();
}
std::string Config::Getformat() const {
    return format;
}
std::string Config::getformat() const {
    return Getformat();
}

void Config::SetlogLevel(const std::string &level) {
    logLevel = level;
}
void Config::SetlogType(const std::string &type) {
    logType = type;
}
void Config::SetlogFilePath(const std::string &path) {
    logFilePath = path;
}
void Config::SetmaxLogSize(const std::string &size) {
    maxLogSize = size;
}
void Config::Setformat(const std::string &fmt) {
    format = fmt;
}
void Config::setlogLevel(const std::string &level) {
    SetlogLevel(level);
}
void Config::setlogType(const std::string &type) {
    SetlogType(type);
}
void Config::setlogFilePath(const std::string &path) {
    SetlogFilePath(path);
}
void Config::setmaxLogSize(const std::string &size) {
    SetmaxLogSize(size);
}
void Config::setformat(const std::string &fmt) {
    Setformat(fmt);
}
