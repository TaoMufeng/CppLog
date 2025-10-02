#pragma once

#include <mutex>
#include <memory>
#include "LogWriter.hpp"
#include "FileWriter.hpp"
class LogFileWriter : public LogWriter{
private:
    std::string logFilePath;
    std::mutex fileMutex;
    FileWriter<std::string> fileWriter;
    void SetLogPath(const std::string &path);
    void Write(const std::string &message);
public:
    void setLogPath(const std::string &path) override;
    void write(const std::string &message) override;
};
