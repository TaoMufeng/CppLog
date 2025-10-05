#include <iostream>
#include "../include/Log/LogFileWriter.hpp"
void LogFileWriter::SetLogPath(const std::string &path) {
    logFilePath = path;
}

void LogFileWriter::Write(const std::string &message) {
    std::lock_guard<std::mutex> lock(fileMutex);
    fileWriter.setConfig(logFilePath, std::ios::app);
    fileWriter.write(message);
}
void LogFileWriter::setLogPath(const std::string &path) {
    SetLogPath(path);
}
void LogFileWriter::write(const std::string &message) {
    Write(message);
}
