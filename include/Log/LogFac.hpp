#pragma once

#include <memory>
#include "LogWriter.hpp"
#include "enum.hpp"

class LogFac {

public:
    static std::unique_ptr<LogWriter> CreateWriter(LogType type);
};