#include "../include/Log/LogConsoleWriter.h"
#include <iostream>

void LogConsoleWriter::Write(const std::string &message) {
    std::lock_guard<std::mutex> lock(consoleMutex);
    std::cout << message << std::endl;
}
void LogConsoleWriter::write(const std::string &message) {
    Write(message);
}

void LogConsoleWriter::SetLogPath(const std::string &path) {
    // Console writer does not use a log path, so this is a no-op.
}

void LogConsoleWriter::setLogPath(const std::string &path) {
    SetLogPath(path);
}
