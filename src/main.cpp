#include "../include/Log/Log.hpp"
#include "../include/Log/LogSystem.hpp"
#include <string>
#include <thread>
#include <vector>

int main() {
    Config config;
    config.setlogLevel("INFO");
    config.setlogType("CONSOLE");
    config.setlogFilePath("log.txt");
    config.setmaxLogSize("1048576"); // 1 MB
    config.setformat("{time} [{level}]{thread_id} {file}:{line} {message}");
    SETCONFIG("D:/Project/CppProject/Log/config/log_config.txt", config);
    LOADCONFIG("D:/Project/CppProject/Log/config/log_config.txt");
    LOG_INFO("Application started");
    // Your application code here
    LOG_INFO("Application finished");
   /* std::vector<std::thread> threads;
    for (int i = 0; i < 100; ++i) {
        threads.emplace_back([i]() {

            for (int j = 0; j < 100; ++j) {
                LOG_INFO("Debug message from thread " + std::to_string(i) + " - " + std::to_string(j));
            }
        });
    }
    for (auto& t: threads) {
        t.join();
    }

*/
    return 0;
}