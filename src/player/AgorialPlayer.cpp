//
// Created by Jonathan Rumion on 8/13/15.
//

#include "AgorialPlayer.h"

AgorialPlayer::AgorialPlayer(){

    m_posX = 20;
    m_posY = 20;

}

void AgorialPlayer::setPosX(int x){

    std::unique_lock<std::mutex>mlock(m_posXMutex);
    m_posX = x;
    mlock.unlock();

}


void AgorialPlayer::setPosY(int y){

    std::unique_lock<std::mutex>mlock(m_posYMutex);
    m_posY = y;
    mlock.unlock();

}


int AgorialPlayer::getPosX(){

    int posX;

    std::unique_lock<std::mutex>mlock(m_posXMutex);
    posX = m_posX;
    mlock.unlock();

    return posX;

}


int AgorialPlayer::getPosY(){

    int posY;

    std::unique_lock<std::mutex>mlock(m_posYMutex);
    posY = m_posY;
    mlock.unlock();

    return posY;

}