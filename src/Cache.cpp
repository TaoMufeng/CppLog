#include "Log/Cache.hpp"
#include "Log/LogFac.hpp"
#include "Log/Util.hpp"
Cache &Cache::Instance() {
    static Cache instance;
    return instance;
}

void Cache::addLog(const std::string &message, LogType type, const std::string& path, const std::string& size, int &number) {
    std::lock_guard<std::mutex> lock(mtx);
    this->number = number;
    cache.push_back(message);
    flush(type, path, size, number);
}
void Cache::flush(LogType type, const std::string& path, const std::string& size, int &number) {
    if(!cache.empty()) {
        auto writer = LogFac::CreateWriter(type);
        for(auto &log : cache) {
            writer->setLogPath(Util::getCurrentDay() + "_" + std::to_string(number) + "_" + path);
            writer->write(log);
        }
        cache.clear();
    }
    if(Util::fileSize(Util::getCurrentDay() + "_" + std::to_string(number) + "_" + path) >= std::stoll(size)) {
            number++;
    }
}
Cache::~Cache() {
    flush(LogType::FILE, "log.txt", "1048576", number);
}
