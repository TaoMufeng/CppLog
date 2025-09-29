#pragma once

#include <memory>
#include "LogWriter.h"
#include "enum.h"

class LogFac {

public:
    static std::unique_ptr<LogWriter> CreateWriter(LogType type);
};