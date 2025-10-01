#include "../include/Log/LogFac.h"
#include "../include/Log/LogConsoleWriter.h"
#include "../include/Log/LogFileWriter.h"

std::unique_ptr <LogWriter> LogFac::CreateWriter(LogType type) {
    if (type == LogType::CONSOLE) {
        return std::make_unique<LogConsoleWriter>();
    } else if (type == LogType::FILE) {
        return std::make_unique<LogFileWriter>();
    }
    return nullptr;
}
