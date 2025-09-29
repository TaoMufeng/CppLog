#pragma once

#include "LogWriter.h"
#include <mutex>
class LogConsoleWriter : public LogWriter {
private:
    std::mutex consoleMutex;
public:
    void write(const std::string& message) override;
};