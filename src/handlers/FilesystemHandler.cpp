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


bool FilesystemHandler::createDirectory(std::string dirName) {

    boost::filesystem::path newDir(dirName);

    if(doesFileExist(dirName)){

        std::cerr << "Failed to create directory: " + dirName + " - Directory Already Exists" << std::endl;
        return false;
    }


    else {
        try {
            boost::filesystem::create_directory(newDir);
            return true;
        }
        catch(std::exception& e) {
            std::cerr << "error: " << e.what() << std::endl;
            return false;
        }
        catch(...){
            std::cerr << "Exception of unknown type!" << std::endl;
            return false;
        }
    }

}


bool FilesystemHandler::doesFileExist(std::string fileName) {

    boost::filesystem::path checkFile(fileName);

    return boost::filesystem::exists(checkFile);

}