//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_CLIENTNETWORKMANAGER_H
#define AGORIAL_CLIENTNETWORKMANAGER_H

#include "network/zmq.hpp"
#include "util/MsgQueue.h"

#include <string>
#include <thread>
#include <vector>
#include <msgpack.hpp>


class ClientNetworkManager {

public:

    static ClientNetworkManager* I();

    bool init(int port, std::string serverHost, int threads);
    bool sendMessage(std::vector<std::string> message);

    bool responseReady();
    int responseCount();
    std::vector<std::string> getResponse();
    void addResponse(std::vector<std::string> response);

private:

    ClientNetworkManager();
    ~ClientNetworkManager();

    ClientNetworkManager(ClientNetworkManager const&){};             // copy constructor is private
    void operator=(ClientNetworkManager const&){};  // assignment operator is private
    static ClientNetworkManager* m_pInstance;

    static void * communicationsThread(void *arg,  MsgQueue<std::vector<std::string> >* commandQueue);

    int m_serverPort;
    std::string m_serverHost;
    bool m_initialized;

    int m_connectionThreads;

    std::vector<std::thread> m_threadList;
    zmq::context_t m_context;

    MsgQueue<std::vector<std::string> > m_ClientCommandQueue;

    MsgQueue<std::vector<std::string> > m_responseQueue;

};


#endif //AGORIAL_CLIENTNETWORKMANAGER_H
