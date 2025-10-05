#pragma once

#include<string>
#include "Log.hpp"

class LogWriter {
public:
    virtual ~LogWriter() = default;
    virtual void write(const std::string& message) = 0;
    virtual void setLogPath(const std::string& path) = 0;
};