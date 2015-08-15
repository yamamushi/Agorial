//
// Created by Jonathan Rumion on 8/13/15.
//

#include "CertHandler.h"
#include "parsers/ServerConfigParser.h"
#include "FilesystemHandler.h"

#include <iostream>

CertHandler* CertHandler::m_pInstance = NULL;

CertHandler* CertHandler::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new CertHandler;

    return m_pInstance;
}



CertHandler::CertHandler() {

    m_initialized = false;

}


bool CertHandler::init(){

    m_certPath = ServerConfigParser::I()->getCertPath().c_str();

    if(FilesystemHandler::I()->doesFileExist(m_certPath)){
        m_initialized = true;
        return true;
    }

    if(zsys_dir_create(m_certPath.c_str())){

        std::cerr << "Error creating Cert Directory" << std::endl;
        return false;
    }

    m_initialized = true;

    return true;
}


bool CertHandler::generate(std::string certName, std::string description){

    if(!m_initialized){

        std::cerr << "Error CertHandler Not Initialized hint: CertHandler::I()->init();" << std::endl;
        return false;
    }

    if(FilesystemHandler::I()->doesFileExist(certName+".pub") || FilesystemHandler::I()->doesFileExist(certName+".key")){

        std::cerr << "Error File Exists" << std::endl;
        return false;
    }

    zcert_t * outputCert = zcert_new();

    zcert_set_meta(outputCert, certName.c_str(), description.c_str());

    //zcert_save_public(outputCert, std::string(ServerConfigParser::I()->getCertPath()+certName.c_str()+".pub").c_str());
    zcert_save(outputCert, std::string(ServerConfigParser::I()->getCertPath()+certName+".key").c_str());

    // Not sure why this is erroring in CLion
    zcert_destroy(&outputCert);

    return true;
}