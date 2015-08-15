//
// Created by Jonathan Rumion on 8/13/15.
//

#include "ClientNetworkManager.h"

#include <iostream>
#include <pthread.h>
#include <thread>
#include <functional>
#include <msgpack.hpp>

#include "network/zhelpers.hpp"


ClientNetworkManager* ClientNetworkManager::m_pInstance = NULL;


ClientNetworkManager* ClientNetworkManager::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new ClientNetworkManager;

    return m_pInstance;
}

ClientNetworkManager::ClientNetworkManager() {

    m_initialized = false;

}

bool ClientNetworkManager::init(int port, std::string serverHost, int threads){

    if(port < 1000 || port > 65535){

        std::cerr << "Error: ClientNetworkManager port out of range" << std::endl;
        return false;
    }
    m_serverPort = port;
    m_serverHost = serverHost;
    m_connectionThreads = threads;

    //  Prepare our context and socket
    m_context = zmq::context_t(1);
    zmq::socket_t socket(m_context, ZMQ_REQ);

    for(int x = 0; x < 1; x++){
        m_threadList.push_back(std::thread(communicationsThread, &m_context, &m_ClientCommandQueue));
    }

    m_initialized = true;

    return true;
}

void * ClientNetworkManager::communicationsThread(void* arg,  MsgQueue<std::vector<std::string> >* commandQueue) {

    zmq::context_t *context = (zmq::context_t *) arg;
    zmq::socket_t socket(*context, ZMQ_REQ);
    s_set_id(socket);          //  Makes tracing easier
    socket.connect("tcp://localhost:4200");

    // Loop Forever until otherwise notified to join();
    while(true)
    {
        // Grab our command vector from the Queue
        std::vector<std::string> vec = commandQueue->pop();

        if(vec.at(0) == "ShutdownThreads"){
            // Push the command back onto the queue for any
            // Threads that are still running and pulling from the queue.
            std::cerr << "Connection Thread Shutting Down" << std::endl;
            commandQueue->push(vec);
            break;
        }

        // serialize it into simple buffer.
        msgpack::sbuffer sbuf;
        msgpack::pack(sbuf, vec);

        // create request object, fill it up and send it
        zmq::message_t request(sbuf.size());
        memcpy(request.data(), sbuf.data(), sbuf.size());
        socket.send(request);


        //  Get the reply.
        zmq::message_t incomingResponse;
        socket.recv(&incomingResponse);

        msgpack::sbuffer incomingBuffer;
        incomingBuffer.write(static_cast<const char *>(incomingResponse.data()), incomingResponse.size());

        // deserialize it.
        msgpack::unpacked msg;
        msgpack::unpack(&msg, incomingBuffer.data(), incomingBuffer.size());

        // print the deserialized object.
        msgpack::object obj = msg.get();
        std::cout << obj << std::endl;

        // convert it into statically typed object.
        std::vector<std::string> rvec;
        obj.convert(&rvec);
        std::cout << rvec.at(0) << std::endl;

        ClientNetworkManager::I()->addResponse(rvec);

    }

    return (NULL);

}


bool ClientNetworkManager::sendMessage(std::vector<std::string> message) {

    /*
    if(message.size() < 2){

        std::cerr << "Error: Cannot send message of size < 2" << std::endl;
        return false;

    }
     */

    if(!m_initialized){

        std::cerr << "Error: ClientNetworkManager Not Initialized" << std::endl;
        return false;
    }

    m_ClientCommandQueue.push(message);

    return true;

}


bool ClientNetworkManager::responseReady(){

    if(m_responseQueue.size() > 0){
        return true;
    }
    else{
        return false;
    }
}


int ClientNetworkManager::responseCount(){

    int count;
    count = m_responseQueue.size();
    return count;
}


std::vector<std::string> ClientNetworkManager::getResponse(){

    std::vector<std::string> response;
    response = m_responseQueue.pop();
    return response;

}


void ClientNetworkManager::addResponse(std::vector<std::string> response){

    m_responseQueue.push(response);

}



ClientNetworkManager::~ClientNetworkManager() {

    for(auto &t : m_threadList){
        t.join();
    }

}