#pragma once

#include <string>
#include "enum.hpp"
class Util {
private:
    static std::string GetCurrentTime();
    static std::string Replace(std::string str, const std::string& oldstr, const std::string& newstr);
    static std::string LogLevelToString(LogLevel level);
    static std::string LogTypeToString(LogType type);
    static std::string Trim(std::string str);
    static std::string Input(const std::string& prompt);
    static LogLevel StringToLogLevel(const std::string& str);
    static LogType StringToLogType(const std::string& str);
    static std::string ToLower(const std::string& str);
    static std::string GetCurrentDay();
    static size_t FileSize(const std::string& filePath);
    static size_t ParseSize(const std::string& sizeStr);
public:
    static std::string getCurrentTime();
    static std::string replace(std::string str, const std::string& oldstr, const std::string& newstr);
    static std::string logLevelToString(LogLevel level);
    static std::string logTypeToString(LogType type);
    static std::string trim(std::string str);
    static std::string input(const std::string& prompt);
    static LogLevel stringToLogLevel(const std::string& str);
    static LogType stringToLogType(const std::string& str);
    static std::string toLower(const std::string& str);
    static std::string getCurrentDay();
    static size_t fileSize(const std::string& filePath);
    static size_t parseSize(const std::string& sizeStr);
};
