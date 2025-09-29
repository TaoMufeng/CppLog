cmake_minimum_required(VERSION 3.10)

project(Log)

set(CMAKE_CXX_STANDARD 23)

add_executable(Log main.cpp
        Log.cpp
        Log.h
        enum.h
        LogConfigReader.cpp
        LogConfigReader.h
        FileReader.cpp
        FileReader.h
        LogFac.cpp
        LogFac.h
        LogWriter.h
        FileWriter.cpp
        FileWriter.h
        LogConsoleWriter.cpp
        LogConsoleWriter.h
        Util.cpp
        Util.h
        LogFileWriter.cpp
        LogFileWriter.h
)