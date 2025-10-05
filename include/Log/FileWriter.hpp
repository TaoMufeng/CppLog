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
    void SetConfig(const std::string& path, std::ios::openmode mode)
    {
        if (fileStream.is_open()) {
            fileStream.close();
        }
        filePath = path;
        fileStream.open(filePath, mode);
        if (!fileStream.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }
    }
public:
    FileWriter() = default;
    FileWriter(const std::string& path, std::ios::openmode mode = std::ios::app)
    {
        SetConfig(path, mode);
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
    void setConfig(const std::string& path, std::ios::openmode mode)
    {
        SetConfig(path, mode);
    }
};
