#include "../include/Log/LogFac.hpp"
#include "../include/Log/LogConsoleWriter.hpp"
#include "../include/Log/LogFileWriter.hpp"

std::unique_ptr <LogWriter> LogFac::CreateWriter(LogType type) {
    if (type == LogType::CONSOLE) {
        return std::make_unique<LogConsoleWriter>();
    } else if (type == LogType::FILE) {
        return std::make_unique<LogFileWriter>();
    }
    return nullptr;
}
