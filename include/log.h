#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>

// Log level enumeration
enum class LogLevel {
    CRITICAL,
    ERROR,
    WARNING,
    INFO,
    DEBUG,
    TRACE,
};

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();

    // Log a message with the specified log level
    void log(LogLevel level, const std::string& message);

    // Set the log level dynamically
    void setLogLevel(LogLevel level);

private:
    std::ofstream logFile;
    LogLevel currentLogLevel = LogLevel::DEBUG; // Default log level
    std::map<LogLevel, std::string> logLevelNames;

    // Helper functions
    std::string getCurrentTime();
    std::string levelToString(LogLevel level);
};

extern Logger logger;  // Declare a global logger instance

#endif // LOG_H
