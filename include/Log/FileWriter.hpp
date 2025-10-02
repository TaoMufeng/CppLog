#pragma once

#include <string>
#include <fstream>
#include <mutex>
template <typename T>
class FileWriter {
private:
    std::ofstream fileStream;
    std::string filePath;
    std::mutex fileMutex;
    bool Write(const T &message)
    {
        fileStream << message << std::endl;
        return true;
    }
    void SetFilePath(const std::string& path)
    {
        if (fileStream.is_open()) {
            fileStream.close();
        }
        filePath = path;
        fileStream.open(filePath, std::ios::app);
        if (!fileStream.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }
    }
public:
    FileWriter() = default;
    FileWriter(const std::string& path)
    {
        SetFilePath(path);
    }
    bool write(const T &message)
    {
        std::lock_guard<std::mutex> lock(fileMutex);
        return Write(message);
    }
    ~FileWriter()
    {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }
    void setFilePath(const std::string& path)
    {
        SetFilePath(path);
    }
};
