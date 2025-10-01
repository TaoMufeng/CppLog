config{
    logLevel: "INFO", // DEBUG, INFO, WARN, ERROR, FATAL
    logType: "console", // console, file, Remote
    logFilePath: "app.log",
    maxFileSize: 5,
    logFormat: //"{time} {level} {thread_id} {message} {file}:{line}"
}

use SETCONFIG(filePath, config) to set log config
use LOADCONFIG(filePath) to load log config
use LOG_DEBUG(msg), LOG_INFO(msg), LOG_WARN(msg), LOG_ERROR(msg), LOG_FATAL(msg) to log messages
