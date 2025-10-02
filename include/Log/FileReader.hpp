#pragma once
#include <string>
#include <fstream>
#include <mutex>

class FileReader {
private:
    std::string filePath;
    std::ifstream fileStream;
    std::mutex fileMutex;
    std::string Read(const std::string& key);
public:
    explicit FileReader(std::string filePath);
    std::string read(const std::string& key);
    ~FileReader();
};