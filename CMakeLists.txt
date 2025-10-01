cmake_minimum_required(VERSION 3.10)

project(Log)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_LIBRARIES ON)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES ON)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_LIBRARIES ON)

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
        Config.cpp
        Config.h
        LogConfigWriter.cpp
        LogConfigWriter.h
        LogSystem.cpp
        LogSystem.h
)
