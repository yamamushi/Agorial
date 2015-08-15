//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_AGORIALPLAYER_H
#define AGORIAL_AGORIALPLAYER_H

#include <thread>
#include <vector>

class AgorialPlayer {

public:

    AgorialPlayer();

    /*
    // Make it Non-Copyable
    AgorialPlayer(AgorialPlayer const&) = delete;
    AgorialPlayer& operator=(AgorialPlayer const&) = delete;

    // Make it Movable
    AgorialPlayer(AgorialPlayer&&) = default;
    AgorialPlayer& operator=(AgorialPlayer&&) = default;
*/


    void setPosX(int x);
    void setPosY(int y);
    int getPosX();
    int getPosY();

private:

    int m_posX;
    int m_posY;

    std::mutex(m_posXMutex);
    std::mutex(m_posYMutex);

};


#endif //AGORIAL_AGORIALPLAYER_H
