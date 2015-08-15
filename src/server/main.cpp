//
// Created by Jonathan Rumion on 8/13/15.
//

#include "network/zmq.hpp"
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>

#define sleep(n)    Sleep(n)
#endif

#include <msgpack.hpp>
#include <czmq.h>

#include "parsers/ServerConfigParser.h"
#include "handlers/CertHandler.h"
#include "managers/ServerNetworkManager.h"

int main (int argc, char * argv[]) {


    ServerConfigParser::I()->loadCommandLine(argc, argv);
    ServerConfigParser::I()->parse();
    ServerConfigParser::I()->saveConfig();

    CertHandler::I()->init();
    CertHandler::I()->generate("ServerCert", "Alpha 0.0.1 Server Certificate");

    ServerNetworkManager::I()->init(ServerConfigParser::I()->getLoginServerPort(),
                                    ServerConfigParser::I()->getCertPath()+"ServerCert.key",
                                    ServerConfigParser::I()->getServerListenerThreads());


    return 0;
}