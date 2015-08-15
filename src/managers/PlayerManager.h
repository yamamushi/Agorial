//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_PLAYERMANAGER_H
#define AGORIAL_PLAYERMANAGER_H

#include <thread>
#include <vector>
#include <memory>

#include "player/AgorialPlayer.h"

class PlayerManager {

public:

    static PlayerManager* I();

    void setMaxPlayers(int players);
    int getMaxPlayers();

    void addNewPlayer();

    int getPlayerPosX(int PlayerID);
    int getPlayerPosY(int PlayerID);
    bool setPlayerPosX(int PlayerID, int posX);
    bool setPlayerPosY(int PlayerID, int posY);


private:

    PlayerManager();
    ~PlayerManager(){};

    PlayerManager(PlayerManager const&){};             // copy constructor is private
    void operator=(PlayerManager const&){};  // assignment operator is private
    static PlayerManager* m_pInstance;


    std::vector<std::shared_ptr<AgorialPlayer> > m_playerList;
    std::mutex(m_playerListMutex);

    int m_maxPlayers;
    std::mutex(m_maxPlayersMutex);

    //std::condition_variable(cond_);

};


#endif //AGORIAL_PLAYERMANAGER_H
