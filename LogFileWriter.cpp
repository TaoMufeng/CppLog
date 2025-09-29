#include <iostream>
#include "LogFileWriter.h"
void LogFileWriter::SetLogPath(const std::string &path) {
    logFilePath = path;
    std::cout << logFilePath << std::endl;
}

void LogFileWriter::Write(const std::string &message) {
    std::lock_guard<std::mutex> lock(fileMutex);
    fileWriter.setFilePath(logFilePath);
    std::cout << fileWriter.write(message) << std::endl;
}
void LogFileWriter::setLogPath(const std::string &path) {
    SetLogPath(path);
}
void LogFileWriter::write(const std::string &message) {
    Write(message);
}
