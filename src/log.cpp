#include "log.h"


// Initialize the logger instance
Logger logger("logs/debug.log");

// Constructor that opens the log file and initializes log level names
Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::out);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }

    // Initialize log level name mappings
    logLevelNames[LogLevel::CRITICAL] = "CRITICAL";
    logLevelNames[LogLevel::ERROR] = "ERROR";
    logLevelNames[LogLevel::WARNING] = "WARNING";
    logLevelNames[LogLevel::INFO] = "INFO";
    logLevelNames[LogLevel::DEBUG] = "DEBUG";
    logLevelNames[LogLevel::TRACE] = "TRACE";
}

// Destructor to close the log file
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Log a message with the specified log level
void Logger::log(LogLevel level, const std::string& message) {
    if (level <= currentLogLevel) {  // Log only if the message level is at or above the current log level
        logFile << getCurrentTime() << " - " << levelToString(level) << " - " << message << std::endl;
        logFile.flush();  // Ensure the message is written to the file immediately
    }
}

// Set the current log level
void Logger::setLogLevel(LogLevel level) {
    currentLogLevel = level;
}

// Get the current time in a human-readable format
std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    return std::string(buffer);
}

// Convert the log level enum to a string
std::string Logger::levelToString(LogLevel level) {
    return logLevelNames[level];
}
