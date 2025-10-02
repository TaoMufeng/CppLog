cmake_minimum_required(VERSION 3.10)

project(Log)
project(text)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_LIBRARIES ON)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES ON)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_LIBRARIES ON)

add_library(Log SHARED
        ../src/Log.cpp
        ../src/LogConfigReader.cpp
        ../src/FileReader.cpp
        ../src/LogFac.cpp
        ../src/LogConsoleWriter.cpp
        ../src/Util.cpp
        ../src/LogFileWriter.cpp
        ../src/Config.cpp
        ../src/LogConfigWriter.cpp
        ../src/LogSystem.cpp
)
add_executable(text ../src/main.cpp)
target_link_libraries(text Log)
