#include "LogFac.h"
#include "LogConsoleWriter.h"

std::unique_ptr <LogWriter> LogFac::CreateWriter(LogType type) {
    if (type == LogType::CONSOLE) {
        return std::make_unique<LogConsoleWriter>();
    }
    return nullptr;
}
