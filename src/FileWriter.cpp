#include "../include/Log/FileWriter.h"
#include "../include/Log/Util.h"
FileWriter::FileWriter(const std::string &path) {
    this->filePath = path;
    fileStream.open(this->filePath, std::ios::out | std::ios::app);
}

bool FileWriter::Write(const std::string &message) {
    std::lock_guard<std::mutex> lock(fileMutex);
    fileStream << message << std::endl;
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

void FileWriter::SetFilePath(const std::string &path) {
    filePath = path;
    if (fileStream.is_open()) {
        fileStream.close();
    }
    fileStream.open(filePath, std::ios::out | std::ios::app);
}
void FileWriter::setFilePath(const std::string &path) {
    SetFilePath(path);
}

FileWriter::FileWriter() {

}
