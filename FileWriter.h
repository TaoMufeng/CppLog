#pragma once

#include <string>
#include <fstream>
#include <mutex>
class FileWriter {
private:
    std::ofstream fileStream;
    std::string filePath;
    std::mutex fileMutex;
    bool Write(const std::string& message);
public:
    explicit FileWriter(const std::string& path);
    bool write(const std::string& message);
    ~FileWriter();
};
