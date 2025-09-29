#include "Log.h"
#include "Util.h"
#include "LogFac.h"
#include <iostream>
#include <thread>
Log &Log::Instance() {
    static Log instance;
    return instance;
}

Log::Log() {
    logType = LogType::CONSOLE;
    logLevel = LogLevel::DEBUG;
    logFilePath = "app.log";
    maxLogSize = "10MB";
}

void Log::SetLogeType(const std::string& type) {
    if (type == "console") {
        logType = LogType::CONSOLE;
    } else if (type == "file") {
        logType = LogType::FILE;
    } else if(type == "remote") {
        logType = LogType::REMOTE;
    } else {
        logType = LogType::CONSOLE;
        std::cerr << "Unknown log type: " << type << ". Defaulting to CONSOLE." << std::endl;
    }
}

void Log::setLogType(const std::string& type) {
    SetLogeType(type);
}
void Log::SetLogLevel(const std::string& level) {
    if (level == "debug") {
        logLevel = LogLevel::DEBUG;
    } else if (level == "info") {
        logLevel = LogLevel::INFO;
    } else if (level == "warning") {
        logLevel = LogLevel::WARNING;
    } else if (level == "error") {
        logLevel = LogLevel::ERROR;
    } else if (level == "fatal") {
        logLevel = LogLevel::FATAL;
    } else {
        logLevel = LogLevel::DEBUG;
        std::cerr << "Unknown log level: " << level << ". Defaulting to DEBUG." << std::endl;
    }
}
void Log::setLogLevel(const std::string& level) {
    SetLogLevel(level);
}
void Log::SetLogFilePath(const std::string &path) {
    logFilePath = path;
}
void Log::setLogFilePath(const std::string &path) {
    SetLogFilePath(path);
}
void Log::SetMaxLogSize(const std::string &size) {
    maxLogSize = size;
}
void Log::setMaxLogSize(const std::string &size) {
    SetMaxLogSize(size);
}

void Log::LogMessage(const std::string &message, LogLevel level, const std::string& threadId, const std::string& file, int line) {
    if (level < logLevel) {
        return;
    }
    std::string logMessage = Util::trim(format);
    logMessage = Util::replace(logMessage, "time", Util::getCurrentTime());
    logMessage = Util::replace(logMessage, "level", Util::logLevelToString(level));
    logMessage = Util::replace(logMessage, "message", message);
    logMessage = Util::replace(logMessage, "thread_id", threadId);
    logMessage = Util::replace(logMessage, "file:line", file + ":" + std::to_string(line));
    LogFac::CreateWriter(logType)->write(logMessage);
}

void Log::SetFormat(const std::string &fmt) {
    format = fmt;
}
void Log::setFormat(const std::string &fmt) {
    SetFormat(fmt);
}

void Log::logMessage(const std::string &message, LogLevel level, const std::string &threadId, const std::string &file,
                     int line) {
    LogMessage(message, level, threadId, file, line);
}
