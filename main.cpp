#include "Log.h"
#include "LogConfigReader.h"
#include <iostream>
#include "Util.h"
#include <thread>
int main() {
    LogConfigReader configReader(R"(D:\Project\CppProject\Log\config.txt)");
    LOG_DEBUG("This is a debug message.");
    LOG_INFO("This is an info message.");
    LOG_WARNING("This is a warning message.");
    LOG_ERROR("This is an error message.");
    LOG_FATAL("This is a fatal message.");
    auto test = []() {
        LOG_DEBUG("This is a debug message from thread.");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() %1000));
        LOG_INFO("This is an info message from thread.");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() %1000));
        LOG_WARNING("This is a warning message from thread.");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() %1000));
        LOG_ERROR("This is an error message from thread.");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() %1000));
        LOG_FATAL("This is a fatal message from thread.");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() %1000));
    };
    std::thread t1(test);
    std::thread t2(test);
    t1.join();
    t2.join();
    return 0;
}