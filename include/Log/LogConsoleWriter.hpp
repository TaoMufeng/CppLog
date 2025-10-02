#pragma once

#include "LogWriter.hpp"
#include <mutex>
class LogConsoleWriter : public LogWriter {
private:
    std::mutex consoleMutex;
    void Write(const std::string& message);
    void SetLogPath(const std::string& path);
public:
    void write(const std::string& message) override;
    void setLogPath(const std::string& path) override;
};