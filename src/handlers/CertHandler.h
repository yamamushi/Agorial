//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_CERTHANDLER_H
#define AGORIAL_CERTHANDLER_H

#include <czmq.h>
#include <string>

class CertHandler {

public:

    static CertHandler* I();

    bool init();
    bool generate(std::string certName, std::string description="");

private:

    CertHandler();

    CertHandler(CertHandler const&){};             // copy constructor is private
    void operator=(CertHandler const&){};  // assignment operator is private
    static CertHandler* m_pInstance;

    std::string m_certPath;

    bool m_initialized;


};


#endif //AGORIAL_CERTHANDLER_H
