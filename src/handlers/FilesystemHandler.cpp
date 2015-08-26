//
// Created by Jonathan Rumion on 8/12/15.
//

#include "FilesystemHandler.h"
#include <boost/filesystem.hpp>
#include <iostream>


FilesystemHandler* FilesystemHandler::m_pInstance = NULL;

FilesystemHandler* FilesystemHandler::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new FilesystemHandler;

    return m_pInstance;
}


std::pair<std::string, LogLevel>  FilesystemHandler::createDirectory(std::string dirName) {

    boost::filesystem::path newDir(dirName);

    if(doesFileExist(dirName)){
        return std::pair<std::string, LogLevel>("Failed to create directory: " + dirName + " - Directory Already Exists", LogLevel::ERROR);
    }


    else {
        try {
            boost::filesystem::create_directory(newDir);
            return std::pair<std::string, LogLevel>("Directory " + dirName + " Created", LogLevel::INFO);
        }
        catch(std::exception& e) {
            return std::pair<std::string, LogLevel>(e.what(), LogLevel::ERROR);
        }
        catch(...){
            return std::pair<std::string, LogLevel>("FilesystemHandler - Exception of unknown type!", LogLevel::ERROR);
        }
    }

}


bool FilesystemHandler::doesFileExist(std::string fileName) {

    boost::filesystem::path checkFile(fileName);

    return boost::filesystem::exists(checkFile);

}