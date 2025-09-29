#include <chrono>
#include <sstream>
#include <utility>
#include <iostream>
#include "Util.h"


std::string Util::GetCurrentTime() {
    // 获取当前时间的逻辑实现
    //return "2025-09-29 12:00:00"; // 示例返回值
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
std::string Util::getCurrentTime() {
    return GetCurrentTime();
}

std::string Util::Replace(std::string str, const std::string &oldstr, const std::string &newstr) {
    auto pos = str.find(oldstr);
    while (pos != std::string::npos) {
        str.replace(pos, oldstr.length(), newstr);
        pos = str.find(oldstr, pos + newstr.length());
    }
    return str;
}
std::string Util::replace(std::string str, const std::string &oldstr, const std::string &newstr) {
    return Replace(std::move(str), oldstr, newstr);
}

std::string Util::LogLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
        default:
            std::cerr << "Unknown log level enum value: " << static_cast<int>(level) << std::endl;
            return "DEBUG";
    }
}

std::string Util::LogTypeToString(LogType type) {
    switch (type) {
        case LogType::CONSOLE: return "CONSOLE";
        case LogType::FILE: return "FILE";
        case LogType::REMOTE: return "REMOTE";
        default:
            std::cerr << "Unknown log type enum value: " << static_cast<int>(type) << std::endl;
            return "CONSOLE";
    }
}

std::string Util::logLevelToString(LogLevel level) {
    return LogLevelToString(level);
}
std::string Util::logTypeToString(LogType type) {
    return LogTypeToString(type);
}

std::string Util::Trim(std::string str) {
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
    return str;
}
std::string Util::trim(std::string str) {
    return Trim(std::move(str));
}
