#include "Log.h"
#include "LogConfigReader.h"
#include <iostream>
#include "Util.h"
#include <thread>
int main() {

    try {
        LogConfigReader configReader(R"(D:\Project\CppProject\Log\config.txt)");
        LOG_INFO("Creating log directory...");
    } catch (const std::exception &e) {
        std::cerr << "Failed to create directory: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}