#pragma once

#include <string>
#include "enum.h"
#include <thread>

class Log {
private:
    LogType logType;
    LogLevel logLevel;
    std::string logFilePath;
    std::string maxLogSize;
    std::string format;

    Log();

    void SetLogeType(const std::string &type);

    void SetLogLevel(const std::string &level);

    void SetLogFilePath(const std::string &path);

    void SetMaxLogSize(const std::string &size);

    void SetFormat(const std::string &fmt);

    void LogMessage(const std::string &message, LogLevel level, const std::string &threadId, const std::string &file,
                    int line);

public:
    static Log &Instance();

    void setLogType(const std::string &type);

    void setLogLevel(const std::string &level);

    void setLogFilePath(const std::string &path);

    void setMaxLogSize(const std::string &size);

    void setFormat(const std::string &fmt);

    void logMessage(const std::string &message, LogLevel level, const std::string &threadId, const std::string &file,
                    int line);

    ~Log() = default;
};

#define THREAD_ID std::to_string((std::hash<std::thread::id>()(std::this_thread::get_id())))
#define LOG(msg, level) Log::Instance().logMessage(msg, level, THREAD_ID, __FILE__, __LINE__)
#define LOG_DEBUG(msg) LOG(msg, LogLevel::DEBUG)
#define LOG_INFO(msg) LOG(msg, LogLevel::INFO)
#define LOG_WARNING(msg) LOG(msg, LogLevel::WARNING)
#define LOG_ERROR(msg) LOG(msg, LogLevel::ERROR)
#define LOG_FATAL(msg) LOG(msg, LogLevel::FATAL)
