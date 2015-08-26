//
// Created by Jonathan Rumion on 8/13/15.
//

#include "ServerNetworkManager.h"
#include "handlers/FilesystemHandler.h"
#include "managers/PlayerManager.h"
#include "util/ServerGlobalLogger.h"

#include <iostream>
#include <msgpack.hpp>
#include <sstream>

ServerNetworkManager* ServerNetworkManager::m_pInstance = NULL;


ServerNetworkManager* ServerNetworkManager::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new ServerNetworkManager;

    return m_pInstance;
}


ServerNetworkManager::ServerNetworkManager(){

    m_initialized = false;
}


void * ServerNetworkManager::serverCommunicationsThread(void *arg)
{
    zmq::context_t *context = (zmq::context_t *) arg;

    zmq::socket_t socket (*context, ZMQ_REP);
    socket.connect ("inproc://workers");

    // TESTING - REMOVE ME
    PlayerManager::I()->addNewPlayer();

    while (true) {
        zmq::message_t incomingRequest;

        //  Wait for next request from client
        socket.recv(&incomingRequest);
        msgpack::sbuffer incomingBuffer;
        incomingBuffer.write(static_cast<const char *>(incomingRequest.data()), incomingRequest.size());

        // deserialize it.
        msgpack::unpacked msg;
        msgpack::unpack(&msg, incomingBuffer.data(), incomingBuffer.size());

        // print the deserialized object.
        msgpack::object obj = msg.get();

        std::stringstream stringoutstream;
        stringoutstream << obj;
        GlobalLogger::I()->Log(stringoutstream.str(), LogLevel::DEBUG);

        // convert it into statically typed object.
        std::vector<std::string> rvec;
        obj.convert(&rvec);
        GlobalLogger::I()->Log(rvec.at(0), LogLevel::DEBUG);

        std::vector<std::string> outboundResponseVector;


        if(rvec.at(0) == "GetPlayerPosX"){
            outboundResponseVector.push_back("PlayerPosX");
            outboundResponseVector.push_back(std::to_string(PlayerManager::I()->getPlayerPosX(0)));
        }
        else if(rvec.at(0) == "GetPlayerPosY"){
            outboundResponseVector.push_back("PlayerPosY");
            outboundResponseVector.push_back(std::to_string(PlayerManager::I()->getPlayerPosY(0)));
        }
        else if(rvec.at(0) == "SetPlayerPosX"){
            outboundResponseVector.push_back(std::to_string(PlayerManager::I()->setPlayerPosX(0, stoi(rvec.at(1)))));
        }
        else if(rvec.at(0) == "SetPlayerPosY"){
            outboundResponseVector.push_back(std::to_string(PlayerManager::I()->setPlayerPosY(0, stoi(rvec.at(1)))));
        }
        else if(rvec.at(0) == "ShutdownServer"){
            exit(1);
        }

        // serialize it into simple buffer.
        msgpack::sbuffer outgoingBuffer;
        msgpack::pack(outgoingBuffer, outboundResponseVector);

        // create request object, fill it up and send it
        zmq::message_t outgoingResponse(outgoingBuffer.size());
        memcpy(outgoingResponse.data(), outgoingBuffer.data(), outgoingBuffer.size());
        socket.send(outgoingResponse);
    }

    std::cerr << "Thread Closing" << std::endl;

}

bool ServerNetworkManager::init(int port, std::string certPath, int listenerThreads) {

    if(!FilesystemHandler::I()->doesFileExist(certPath)){
        GlobalLogger::I()->Log("Certificate Does Not Exist: " + certPath, LogLevel::ERROR);
        return false;
    }

    if(port > 65535 || port < 1000){
        GlobalLogger::I()->Log("Port Number out of Range: " + std::to_string(port), LogLevel::ERROR);
        return false;
    }

    m_listenPort = port;
    m_listenerThreads = listenerThreads;

    m_context = zmq::context_t();

    zmq::socket_t serverSocket(m_context, ZMQ_ROUTER);
    serverSocket.bind(std::string("tcp://*:"+std::to_string(m_listenPort)));

    zmq::socket_t workerSocket(m_context, ZMQ_DEALER);
    workerSocket.bind("inproc://workers");

    //  Launch pool of worker threads
    for (int i = 0; i < 1; i++) {
        m_threadList.push_back(std::thread(serverCommunicationsThread, &m_context));
    }
    GlobalLogger::I()->Log("Server Initialized", LogLevel::INFO);
    //  Connect work threads to client threads via a queue
    zmq::proxy((void*)serverSocket, (void*)workerSocket, NULL);

    // At this point we have started up a server and we should be listening
    m_initialized = true;

    return true;

}


ServerNetworkManager::~ServerNetworkManager() {

    for(auto &t : m_threadList){
        t.join();
    }

}