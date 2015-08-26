/*
    Created by Jonathan Rumion on 8/23/15.

    Usage:

        bool Log(std::string message, int Level);

        Logging Levels:

        LOG_ALL
        LOG_DEBUG
        LOG_ERROR
        LOG_FATAL
        LOG_WARN
        LOG_INFO
        LOG_OFF

 */


#ifndef AGORIAL_SERVERGLOBALLOGGER_H
#define AGORIAL_SERVERGLOBALLOGGER_H

#include <string>
#include <thread>

#include "types/LogLevels.h"

class GlobalLogger {

public:

    static GlobalLogger* I();

    void Log(std::string Message, LogLevel Level = LogLevel::DEBUG);
    bool SetLoggingLevel(LogLevel Level);
    LogLevel getLoggingLevel(){return m_LoggingLevel;}

private:

    GlobalLogger();

    GlobalLogger(GlobalLogger const&){};             // copy constructor is private
    void operator=(GlobalLogger const&){};  // assignment operator is private
    static GlobalLogger* m_pInstance;

    LogLevel m_LoggingLevel;
    std::string m_logPath;
    std::string m_logDirectory;

    std::mutex(logger_mutex_);
};


#endif //AGORIAL_GLOBALLOGGER_H
