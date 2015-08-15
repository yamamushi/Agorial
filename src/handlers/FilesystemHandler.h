//
// Created by Jonathan Rumion on 8/12/15.
//

#ifndef AGORIAL_FILESYSTEMHANDLER_H
#define AGORIAL_FILESYSTEMHANDLER_H

#include <string>

class FilesystemHandler {

public:

    static FilesystemHandler* I();

    bool doesFileExist(std::string fileName);
    bool createDirectory(std::string dirName);


private:

    FilesystemHandler(){};

    FilesystemHandler(FilesystemHandler const&){};             // copy constructor is private
    void operator=(FilesystemHandler const&){};  // assignment operator is private
    static FilesystemHandler* m_pInstance;

};


#endif //AGORIAL_FILESYSTEMHANDLER_H
