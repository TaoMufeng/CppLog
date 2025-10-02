#include "../include/Log/Log.hpp"
#include "../include/Log/LogSystem.hpp"
#include <string>
int main() {
    Config config;
    config.setlogLevel("INFO");
    config.setlogType("FILE");
    config.setlogFilePath("log.txt");
    config.setmaxLogSize("1048576"); // 1 MB
    config.setformat("{time} [{level}] {file}:{line} {message}");
    SETCONFIG("D:/Project/CppProject/Log/config/log_config.txt", config);
    LOADCONFIG("D:/Project/CppProject/Log/config/log_config.txt");
    LOG_INFO("Application started");
    // Your application code here
    LOG_INFO("Application finished");
}