//
// Created by 吉秋羽 on 2025/9/29.
//

#include "FileWriter.h"
#include "Util.h"

FileWriter::FileWriter(const std::string &path) {
    this->filePath = path;
    fileStream.open(this->filePath, std::ios::out | std::ios::app);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Failed to open file: " + this->filePath);
    }
}

bool FileWriter::Write(const std::string &message) {
    std::lock_guard<std::mutex> lock(fileMutex);
    fileStream << Util::trim(message) << std::endl;
    return fileStream.good();
}

bool FileWriter::write(const std::string &message) {
    return Write(message);
}

FileWriter::~FileWriter() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}
