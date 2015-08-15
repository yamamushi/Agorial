#include <libtcod/libtcod.hpp>
#include <libtcod/mouse.hpp>
#include <libtcod/mouse_types.h>
#include <libtcod/console_types.h>
#include <sdl/sdl.h>
#include <string>
#include <locale>
#include <iostream>
#include <msgpack.hpp>
#include <thread>

#include "network/zmq.hpp"
#include "handlers/KeyboardHandler.h"
#include "parsers/ClientConfigParser.h"
#include "managers/ClientNetworkManager.h"

int main(int argc, char * argv[]) {


    if(ClientConfigParser::I()->loadCommandLine(argc, argv))
        ClientConfigParser::I()->parse();

    ClientConfigParser::I()->saveConfig();

    //
    ClientNetworkManager::I()->init(ClientConfigParser::I()->getLoginServerPort(),
                                    ClientConfigParser::I()->getLoginServerHost(),
                                    ClientConfigParser::I()->getConnectionThreads());

    //std::thread t1(std::bind(&ClientNetworkManager::init, ClientNetworkManager::I()));
    //zmq::context_t m_context(1);
    //zmq::socket_t socket(m_context, ZMQ_REQ);
    //std::thread t1 ( communicationsThread, &m_context);

    // the vector that is going to be sent
    std::vector<std::string> command1;
    command1.push_back("GetPlayerPosX");
    std::vector<std::string> command2;
    command2.push_back("GetPlayerPosY");

    ClientNetworkManager::I()->sendMessage(command1);
    ClientNetworkManager::I()->sendMessage(command2);


    setlocale(LC_ALL, "en_US.UTF-8");
    std::string fontFile(ClientConfigParser::I()->getFontPath()+"font.png");

    TCODConsole::setCustomFont(fontFile.c_str(),
                               TCOD_FONT_LAYOUT_ASCII_INROW | TCOD_FONT_TYPE_GRAYSCALE,
                               32, 2048);

    TCODConsole::initRoot(ClientConfigParser::I()->getScreenX(),
                          ClientConfigParser::I()->getScreenY(),
                          "Agorial Alpha",false,TCOD_RENDERER_SDL);

    bool close = false;
    bool fullscreen = false;
    int playerx=40,playery=25;
    bool showMouse = true;

    TCOD_key_t key;
    TCOD_mouse_t mouse;



    while ( !TCODConsole::isWindowClosed() && !close) {

        while(ClientNetworkManager::I()->responseReady()){

            std::vector<std::string> l_networkResponse = ClientNetworkManager::I()->getResponse();

            if(l_networkResponse.at(0) == "PlayerPosX"){
                playerx = stoi(l_networkResponse.at(1));
            }
            else if(l_networkResponse.at(0) == "PlayerPosY"){
                playery = stoi(l_networkResponse.at(1));
            }
        }

        TCOD_event_t ev = TCODSystem::checkForEvent(TCOD_EVENT_ANY,&key,&mouse);

        if ( ev == TCOD_EVENT_KEY_PRESS && key.vk == TCODK_UP) {
            std::vector<std::string> playerUp;
            playerUp.push_back("SetPlayerPosY");
            playerUp.push_back(std::to_string(playery-1));
            ClientNetworkManager::I()->sendMessage(playerUp);


            std::vector<std::string> getPlayerPosX;
            getPlayerPosX.push_back("GetPlayerPosX");
            std::vector<std::string> getPlayerPosY;
            getPlayerPosY.push_back("GetPlayerPosY");
            ClientNetworkManager::I()->sendMessage(getPlayerPosX);
            ClientNetworkManager::I()->sendMessage(getPlayerPosY);
        }

        else if ( ev == TCOD_EVENT_KEY_PRESS && key.vk == TCODK_DOWN) {
            std::vector<std::string> playerDown;
            playerDown.push_back("SetPlayerPosY");
            playerDown.push_back(std::to_string(playery+1));
            ClientNetworkManager::I()->sendMessage(playerDown);


            std::vector<std::string> getPlayerPosX;
            getPlayerPosX.push_back("GetPlayerPosX");
            std::vector<std::string> getPlayerPosY;
            getPlayerPosY.push_back("GetPlayerPosY");
            ClientNetworkManager::I()->sendMessage(getPlayerPosX);
            ClientNetworkManager::I()->sendMessage(getPlayerPosY);
        }

        else if ( ev == TCOD_EVENT_KEY_PRESS && key.vk == TCODK_LEFT) {
            std::vector<std::string> playerLeft;
            playerLeft.push_back("SetPlayerPosX");
            playerLeft.push_back(std::to_string(playerx-1));
            ClientNetworkManager::I()->sendMessage(playerLeft);


            std::vector<std::string> getPlayerPosX;
            getPlayerPosX.push_back("GetPlayerPosX");
            std::vector<std::string> getPlayerPosY;
            getPlayerPosY.push_back("GetPlayerPosY");
            ClientNetworkManager::I()->sendMessage(getPlayerPosX);
            ClientNetworkManager::I()->sendMessage(getPlayerPosY);
        }

        else if ( ev == TCOD_EVENT_KEY_PRESS && key.vk == TCODK_RIGHT) {
            std::vector<std::string> playerRight;
            playerRight.push_back("SetPlayerPosX");
            playerRight.push_back(std::to_string(playerx+1));
            ClientNetworkManager::I()->sendMessage(playerRight);


            std::vector<std::string> getPlayerPosX;
            getPlayerPosX.push_back("GetPlayerPosX");
            std::vector<std::string> getPlayerPosY;
            getPlayerPosY.push_back("GetPlayerPosY");
            ClientNetworkManager::I()->sendMessage(getPlayerPosX);
            ClientNetworkManager::I()->sendMessage(getPlayerPosY);
        }
        else if ( ev == TCOD_EVENT_KEY_PRESS && key.vk == TCODK_ESCAPE) {
            close = true;
        }

        else if ( ev == TCOD_EVENT_MOUSE_PRESS && !mouse.lbutton_pressed ) {
            std::vector<std::string> mouseX;
            mouseX.push_back("SetPlayerPosX");
            mouseX.push_back(std::to_string(mouse.cx));
            ClientNetworkManager::I()->sendMessage(mouseX);

            std::vector<std::string> mouseY;
            mouseY.push_back("SetPlayerPosY");
            mouseY.push_back(std::to_string(mouse.cy));
            ClientNetworkManager::I()->sendMessage(mouseY);

            std::vector<std::string> getPlayerPosX;
            getPlayerPosX.push_back("GetPlayerPosX");
            std::vector<std::string> getPlayerPosY;
            getPlayerPosY.push_back("GetPlayerPosY");
            ClientNetworkManager::I()->sendMessage(getPlayerPosX);
            ClientNetworkManager::I()->sendMessage(getPlayerPosY);

        }

        else if ( ev == TCOD_EVENT_KEY_PRESS && key.c == KeyboardHandler::KEYPRESS_TYPES::KALT_m ){

            showMouse = !showMouse;
        }

        else if ( ev == TCOD_EVENT_KEY_PRESS && key.c == KeyboardHandler::KEYPRESS_TYPES::KALT_f ){

            fullscreen = !fullscreen;
            TCODConsole::setFullscreen(!TCODConsole::isFullscreen());
        }

        TCODMouse::showCursor(showMouse);

        TCODConsole::root->clear();
        TCODConsole::root->putChar(playerx,playery,9786);
        TCODConsole::root->print(1, 2, ClientConfigParser::I()->getConfigPath().c_str());
        TCODConsole::root->print(1, 3, ClientConfigParser::I()->getLoginServerHost().c_str());
        TCODConsole::root->print(1, 4, std::to_string(ClientConfigParser::I()->getLoginServerPort()).c_str());
        TCODConsole::root->print(1, 5, std::to_string(ClientConfigParser::I()->getScreenX()).c_str());

        TCODConsole::root->print(4, 5, std::to_string(ClientConfigParser::I()->getScreenY()).c_str());

        TCODConsole::root->print(1, 6, ClientConfigParser::I()->getCertPath().c_str());

        TCODConsole::root->print(1, ClientConfigParser::I()->getScreenY() - 5,
                                 std::string(std::to_string(TCODSystem::getFps())+" FPS").c_str());



        // Debugging Key Combos
        int a = key.c;
        if(a < 0)
            TCODConsole::root->print(5, 5, std::to_string(a).c_str());

        TCODConsole::flush();
    }

    return 0;
}