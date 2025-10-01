#include "Log.h"
#include "LogConfigReader.h"
#include <iostream>
#include "Util.h"
#include <thread>
#include "Config.h"
#include "LogConfigWriter.h"
#include "LogSystem.h"

int main() {
    // 设置日志配置文件
    Config config;
    config.setlogLevel("DEBUG");
    config.setlogType("CONSOLE");
    config.setlogFilePath("logs/app.log");
    config.setmaxLogSize("0");
    config.setformat("[{time}] [{level}] [{thread_id}] {message} [{file:line}]");
    SETCONFIG("log_config.txt", config);
    // 加载日志配置文件
    LOADCONFIG("log_config.txt");
    // 输出调试日志
    LOG_DEBUG("Debug message");
    return 0;
}