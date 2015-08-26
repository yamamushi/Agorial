//
// Created by Jonathan Rumion on 8/23/15.
//

#include "ClientGlobalLogger.h"
#include "parsers/ClientConfigParser.h"

#include <iostream>
#include <ios>
#include <fstream>


GlobalLogger* GlobalLogger::m_pInstance = NULL;

GlobalLogger* GlobalLogger::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new GlobalLogger;

    return m_pInstance;
}


GlobalLogger::GlobalLogger(){

    m_LoggingLevel = LOG_OFF;

}

bool GlobalLogger::SetLoggingLevel(int Level) {

    if(Level > LOG_OFF ){
        return false;
    }
    else if(Level < LOG_ALL){
        std::ofstream log("logfile.txt", std::ios_base::app | std::ios_base::out);
    }

}