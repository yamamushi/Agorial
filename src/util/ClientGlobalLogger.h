/*
    Created by Jonathan Rumion on 8/23/15.

    Usage:

        bool Log(std::string message, int Level);

        Logging Levels:

        LOG_ALL
        LOG_DEBUG
        LOG_ERROR
        LOG_FATAL
        LOG_INFO
        LOG_WARN
        LOG_OFF

 */


#ifndef AGORIAL_GLOBALLOGGER_H
#define AGORIAL_GLOBALLOGGER_H

#include <string>

class GlobalLogger {

public:

    enum LogLevels{
        LOG_ALL,
        LOG_DEBUG,
        LOG_ERROR,
        LOG_FATAL,
        LOG_INFO,
        LOG_WARN,
        LOG_OFF
    };

    static GlobalLogger* I();

    bool Log(std::string message, int Level);
    bool SetLoggingLevel(int Level);

private:

    GlobalLogger();

    GlobalLogger(GlobalLogger const&){};             // copy constructor is private
    void operator=(GlobalLogger const&){};  // assignment operator is private
    static GlobalLogger* m_pInstance;

    int m_LoggingLevel;

};


#endif //AGORIAL_GLOBALLOGGER_H
