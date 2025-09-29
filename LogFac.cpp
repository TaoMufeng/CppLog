#include "LogFac.h"
#include "LogConsoleWriter.h"
#include "LogFileWriter.h"

std::unique_ptr <LogWriter> LogFac::CreateWriter(LogType type) {
    if (type == LogType::CONSOLE) {
        return std::make_unique<LogConsoleWriter>();
    } else if (type == LogType::FILE) {
        return std::make_unique<LogFileWriter>();
    }
    return nullptr;
}
