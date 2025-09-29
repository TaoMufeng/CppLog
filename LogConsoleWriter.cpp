#include "LogConsoleWriter.h"
#include <iostream>

void LogConsoleWriter::write(const std::string &message) {
    std::lock_guard<std::mutex> lock(consoleMutex);
    std::cout << message << std::endl;
}
