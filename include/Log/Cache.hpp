#include <string>
#include <vector>
#include <mutex>
#include "enum.hpp"

class Cache {
private:
    std::vector<std::string> cache;
    std::mutex mtx;
    Cache() = default;
    int number;
public:
    ~Cache();
    static Cache& Instance();
    void addLog(const std::string &message, LogType type, const std::string& path, const std::string& size, int &number);

    void flush(LogType type, const std::string &path, const std::string &size, int &number);
};