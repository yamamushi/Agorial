//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_SERVERNETWORKMANAGER_H
#define AGORIAL_SERVERNETWORKMANAGER_H

#include "network/zmq.hpp"
#include <string>
#include <thread>

class ServerNetworkManager {

public:

    static ServerNetworkManager* I();

    bool init(int port, std::string certPath,  int listenerThreads);

private:

    ServerNetworkManager();
    ~ServerNetworkManager();

    ServerNetworkManager(ServerNetworkManager const&){};             // copy constructor is private
    void operator=(ServerNetworkManager const&){};  // assignment operator is private
    static ServerNetworkManager* m_pInstance;

    static void * serverCommunicationsThread(void *arg);

    std::string m_certPath;

    int m_listenPort;
    int m_listenerThreads;

    bool m_initialized;

    std::vector<std::thread> m_threadList;

    zmq::context_t m_context;
};


#endif //AGORIAL_SERVERNETWORKMANAGER_H
