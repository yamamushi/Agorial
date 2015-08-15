//
// Created by Jonathan Rumion on 8/13/15.
//

#include "PlayerManager.h"

PlayerManager* PlayerManager::m_pInstance = NULL;


PlayerManager* PlayerManager::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new PlayerManager;

    return m_pInstance;
}


PlayerManager::PlayerManager(){

//    m_playerList.resize(10);

}


void PlayerManager::setMaxPlayers(int players) {

    std::unique_lock<std::mutex>mlock(m_maxPlayersMutex);
    m_maxPlayers = players;
    mlock.unlock();

}


int PlayerManager::getMaxPlayers(){

    int maxPlayers;

    std::unique_lock<std::mutex>mlock(m_maxPlayersMutex);
    maxPlayers = m_maxPlayers;
    mlock.unlock();

    return maxPlayers;
}


void PlayerManager::addNewPlayer() {

    std::unique_lock<std::mutex>mlock(m_playerListMutex);

    auto l_player = std::shared_ptr<AgorialPlayer>(new AgorialPlayer);
    m_playerList.push_back(l_player);

    mlock.unlock();
}


int PlayerManager::getPlayerPosX(int PlayerID){

    int posX;

    std::unique_lock<std::mutex>mlock(m_playerListMutex);
    posX = m_playerList.at(PlayerID)->getPosX();
    mlock.unlock();

    return posX;
}


int PlayerManager::getPlayerPosY(int PlayerID){

    int posY;

    std::unique_lock<std::mutex>mlock(m_playerListMutex);
    posY = m_playerList.at(PlayerID)->getPosY();
    mlock.unlock();

    return posY;
}


bool PlayerManager::setPlayerPosX(int PlayerID, int posX){

    std::unique_lock<std::mutex>mlock(m_playerListMutex);
    m_playerList.at(PlayerID)->setPosX(posX);
    mlock.unlock();
    return true;

}


bool PlayerManager::setPlayerPosY(int PlayerID, int posY){


    std::unique_lock<std::mutex>mlock(m_playerListMutex);
    m_playerList.at(PlayerID)->setPosY(posY);
    mlock.unlock();

    return true;

}
