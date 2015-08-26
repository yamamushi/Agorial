//
// Created by Jonathan Rumion on 8/23/15.
//

#include "ServerGlobalLogger.h"
#include "parsers/ServerConfigParser.h"

#include <iostream>
#include <ios>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include <fstream>
#include <utility>
#include "handlers/FilesystemHandler.h"

GlobalLogger* GlobalLogger::m_pInstance = NULL;

GlobalLogger* GlobalLogger::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new GlobalLogger;

    return m_pInstance;
}


GlobalLogger::GlobalLogger(){

    m_logPath = "";

    int l_level = ServerConfigParser::I()->getLogLevel();

    if(l_level == 0)
        SetLoggingLevel(LogLevel::ALL);
    else if(l_level == 1)
        SetLoggingLevel(LogLevel::DEBUG);
    else if(l_level == 2)
        SetLoggingLevel(LogLevel::ERROR);
    else if(l_level == 3)
        SetLoggingLevel(LogLevel::FATAL);
    else if(l_level == 4)
        SetLoggingLevel(LogLevel::WARN);
    else if(l_level == 5)
        SetLoggingLevel(LogLevel::INFO);
    else if(l_level == 6)
        SetLoggingLevel(LogLevel::OFF);
    else if(l_level > 6)
        SetLoggingLevel(LogLevel::OFF);
    else if(l_level < 0)
        SetLoggingLevel(LogLevel::ALL);

    m_logDirectory = ServerConfigParser::I()->getRootPath()+"logs/";

    if(!FilesystemHandler::I()->doesFileExist(m_logDirectory)){
        auto createDirResult = FilesystemHandler::I()->createDirectory(m_logDirectory);
        Log(createDirResult.first, createDirResult.second);
    }
    m_logPath = m_logDirectory+"ServerLog.txt";
    Log("Server Global Logger Initialized", LogLevel::INFO);

}

bool GlobalLogger::SetLoggingLevel(LogLevel Level) {

    if(Level > LogLevel::OFF ){
        return false;
    }
    else if(Level < LogLevel::ALL){
        Log("SetLoggingLevel Failed: Level" + std::to_string((int)Level) + " Out of Bounds", LogLevel::ERROR);
        return false;
    }

    m_LoggingLevel = Level;
    return true;
}

void GlobalLogger::Log(std::string Message, LogLevel Level){

    if(m_LoggingLevel > Level || m_LoggingLevel == LogLevel::OFF)
        return;

    if(Level == LogLevel::ALL)
        Level = LogLevel::DEBUG;

    if(Level == LogLevel::DEBUG)
        Message = "<DEBUG>: " + Message;
    else if(Level == LogLevel::ERROR)
        Message = "<ERROR>: " + Message;
    else if(Level == LogLevel::FATAL)
        Message = "<FATAL>: " + Message;
    else if(Level == LogLevel::INFO)
        Message = "<INFO> : " + Message;
    else if(Level == LogLevel::WARN)
        Message = "<WARN> : " + Message;
    else if(Level == LogLevel::OFF) // Why would you set this?
        return;

    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream timeString;
    timeString << std::put_time(std::localtime(&now_time_t), "%c");
    Message = timeString.str() + " " + Message + "\n";

    std::unique_lock<std::mutex>mlock(logger_mutex_);
    if(m_logPath == "") {
        std::cerr << Message << std::endl;
    }
    else{
        std::ofstream log(m_logPath, std::ios_base::app | std::ios_base::out);
        log << Message;
        log.close();
    }
    mlock.unlock();

}