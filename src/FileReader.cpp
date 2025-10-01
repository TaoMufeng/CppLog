#include "../include/Log/FileReader.h"
#include "../include/Log/Util.h"
FileReader::FileReader(std::string filePath) {
    this->filePath = std::move(filePath);
    fileStream.open(this->filePath, std::ios::in);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Failed to open file: " + this->filePath);
    }
}

FileReader::~FileReader() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

std::string FileReader::Read(const std::string &key) {
    std::lock_guard<std::mutex> lock(fileMutex);
    fileStream.clear(); // 清除EOF标志
    fileStream.seekg(0, std::ios::beg); // 重置文件指针到开头
    std::string line;
    while (std::getline(fileStream, line)) {
        line = Util::trim(line); // 去除行首尾空格
        if (line.empty()) {
            continue; // 跳过空行和注释行
        }
        auto equalPos = line.find('=');
        if (equalPos == std::string::npos) {
            continue; // 跳过无效行
        }
        auto keyTrimmed = Util::trim(line.substr(0, equalPos));
        if (keyTrimmed == key) {
            return Util::trim(line.substr(equalPos + 1)); // 返回键对应的值
        }
    }
    return "";
}
std::string FileReader::read(const std::string &key) {
    return Read(key);
}
