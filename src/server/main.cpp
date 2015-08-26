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
#include <async++.h> // TESTING


#include <iostream>
#include <fstream>

#include "parsers/ServerConfigParser.h"
#include "handlers/CertHandler.h"
#include "managers/ServerNetworkManager.h"
#include "octree/octree.h"
#include "noise/OpenSimplexNoise.h"
#include "util/UTF8Util.h"
#include "world/Tile.h"
#include "geometry/VoronoiDiagramGenerator.h"
#include "geometry/Bresenham.h"
#include "util/ServerGlobalLogger.h"
#include "schedulers/TaskSpawner.h"


#ifdef _WIN32
#include <tchar.h>
int _tmain(int argc, _TCHAR* argv[]){
#else
int main (int argc, char * argv[]) {
#endif


    //std::cout << IntToUTF8String(100) << std::endl;
    //std::cout << UTF8StringToInt("d") << std::endl;

    TaskSpawner spawner;

    TestTask testTask;
    std::function<void()> task = std::bind(&TestTask::hello);
    TestTask testTask2;
    std::function<void()> task2 = std::bind(&TestTask::sayHello, "World");
   // spawner.Spawn(task);
   // spawner.Spawn(task2);
    std::vector<std::function<void()> > taskList;
    taskList.push_back(task);
    taskList.push_back(task2);
    spawner.SetTaskList(taskList);
    spawner.Run();

/*
    Octree<Tile> o(256, Tile(0, ColorRGB{0,0,0})); // Create 4096x4096x4096 octree

    struct osn_context *simplexContext;
    struct osn_context *simplexContextDiff;
    struct osn_context *mapLayer;

    open_simplex_noise(3141579, &simplexContext);
    open_simplex_noise(3141579, &simplexContextDiff);
    open_simplex_noise(3141579, &mapLayer);

    if(argc < 6)
        return 0;

    int feature_size = std::stoi(argv[1]);
    int Difffeature_size = std::stoi(argv[2]);


    int startY = std::stoi(argv[3]);
    int startX = std::stoi(argv[4]);
    int startZ = std::stoi(argv[5]);
    for(int simplex_Z = startZ; simplex_Z < startZ+1; simplex_Z++) {
        for (int simplex_Y = startY; simplex_Y < startY + 32; simplex_Y++) {
            std::string output;
            for (int simplex_X = startX; simplex_X < startX + 128; simplex_X++) {


                auto firstIteration = open_simplex_noise3(simplexContext,
                                                 (double) simplex_X / feature_size,
                                                 (double) simplex_Y / feature_size, 0);

                auto secondIteration = open_simplex_noise3(simplexContextDiff,
                                                  (double) simplex_X / Difffeature_size,
                                                  (double) simplex_Y / Difffeature_size, 0);


                auto mapOutput = open_simplex_noise3(mapLayer,
                                                     (double) simplex_X / feature_size,
                                                     (double) simplex_Y / feature_size,
                                                     (double) simplex_Z / feature_size);


                auto value = secondIteration + firstIteration;

                value = mapOutput - value;

                point testPoint{simplex_X, simplex_Y};
                if(!pointInEllipse(testPoint, point{64,16}, 40, 10)){
                    value = value - 0.2;
                }
                if((simplex_Y < startY + 7)){
                    int diff = (startY + 7) - simplex_Y;
                    value = value - (0.2*diff);
                }
                if((simplex_Y > startY + 25)){
                    int diff = simplex_Y - (startY + 25);
                    value = value - (0.2*diff);
                }
                if((simplex_X < startX + 7)){
                    int diff = (startX + 7) - simplex_X;
                    value = value - (0.2*diff);
                }
                if((simplex_X > startX + 121)){
                    int diff = simplex_X - (startX + 121);
                    value = value - (0.2*diff);
                } //

                if (value <= 0.1) {
                    output += "\033[34m~\033[0m";
                }
                if (value > 0.1 && value <= 0.3)
                    output += "\033[33m.\033[0m";
                if (value > 0.3 && value <= 0.5)
                    output += "\033[32m,\033[0m";
                if (value > 0.5 && value <= 0.7)
                    output += "\033[32m+\033[0m";
                if (value > 0.7 && value <= 0.8)
                    output += "\033[31m=\033[0m";
                if (value > 0.8 && value <= 0.85)
                    output += "\033[36m^\033[0m";
                if (value > 0.85 && value <= 0.99)
                    output += "\033[36m^\033[0m";
                if (value > 0.99)
                    output += "\033[37m*\033[0m";

                if(simplex_X == startX + 127) {
                    std::cout << output << std::endl;
                }
                Tile tempTile(100, ColorRGB{10,99,25});
                o.set(simplex_X, simplex_Y, simplex_Z, tempTile);
            }
            output = "";
        }
    }

    std::ofstream myfile;
    myfile.open("output");
    o.writeBinary(myfile);
    myfile.close();
    */

    ServerConfigParser::I()->loadCommandLine(argc, argv);
    ServerConfigParser::I()->parse();
    ServerConfigParser::I()->saveConfig();

    GlobalLogger::I()->Log("Testing", LogLevel::DEBUG);

    CertHandler::I()->init();
    CertHandler::I()->generate("ServerCert", "Alpha 0.0.1 Server Certificate");

    ServerNetworkManager::I()->init(ServerConfigParser::I()->getLoginServerPort(),
                                    ServerConfigParser::I()->getCertPath()+"ServerCert.key",
                                    ServerConfigParser::I()->getServerListenerThreads());


    return 0;
}