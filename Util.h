#pragma once

#include <string>
#include "enum.h"

class Util {
private:
    static std::string GetCurrentTime();
    static std::string Replace(std::string str, const std::string& oldstr, const std::string& newstr);
    static std::string LogLevelToString(LogLevel level);
    static std::string LogTypeToString(LogType type);
    static std::string Trim(std::string str);
public:
    static std::string getCurrentTime();
    static std::string replace(std::string str, const std::string& oldstr, const std::string& newstr);
    static std::string logLevelToString(LogLevel level);
    static std::string logTypeToString(LogType type);
    static std::string trim(std::string str);
};
