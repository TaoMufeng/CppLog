#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Config {
friend std::ostream& operator<<(std::ostream& os, const Config& config);
friend std::istream& operator>>(std::istream& ifs, Config& config);
friend std::ofstream& operator<<(std::ofstream& ofs, const Config& config);
friend std::ifstream& operator>>(std::ifstream& ifs, Config& config);
private:
    std::string logLevel;
    std::string logType;
    std::string logFilePath;
    std::string maxLogSize;
    std::string format;
    std::string GetlogLevel() const;
    std::string GetlogType() const;
    std::string GetlogFilePath() const;
    std::string GetmaxLogSize() const;
    std::string Getformat() const;
    void SetlogLevel(const std::string& level);
    void SetlogType(const std::string& type);
    void SetlogFilePath(const std::string& path);
    void SetmaxLogSize(const std::string& size);
    void Setformat(const std::string& fmt);

public:
    std::string getlogLevel() const;
    std::string getlogType() const;
    std::string getlogFilePath() const;
    std::string getmaxLogSize() const;
    std::string getformat() const;
    void setlogLevel(const std::string& level);
    void setlogType(const std::string& type);
    void setlogFilePath(const std::string& path);
    void setmaxLogSize(const std::string& size);
    void setformat(const std::string& fmt);
    Config() = default;
    ~Config() = default;
};
