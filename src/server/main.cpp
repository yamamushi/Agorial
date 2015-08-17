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

#include <iostream>
#include <fstream>

#include "parsers/ServerConfigParser.h"
#include "handlers/CertHandler.h"
#include "managers/ServerNetworkManager.h"
#include "octree/octree.h"
#include "noise/OpenSimplexNoise.h"

#ifdef _WIN32
#include <tchar.h>
int _tmain(int argc, _TCHAR* argv[]){
#else
int main (int argc, char * argv[]) {
#endif

    /*
    Octree<double> o(4096); // Create 4096x4096x4096 octree containing doubles.

    struct osn_context *simplexContext;

    open_simplex_noise(78745, &simplexContext);
    int feature_size = 24;

    for(int simplex_Z = 0; simplex_Z < 256; simplex_Z++) {

        for (int simplex_Y = 0; simplex_Y < 256; simplex_Y++) {
            for (int simplex_X = 0; simplex_X < 256; simplex_X++) {

                auto value = open_simplex_noise3(simplexContext,
                                                 (double) simplex_X / feature_size,
                                                 (double) simplex_Y / feature_size,
                                                 (double) simplex_Z / feature_size);
                o(simplex_X, simplex_Y, simplex_Z) = value;
                //std::cout << "Value at " << simplex_X << ", " << simplex_Y << ", " << simplex_Z << " : " <<
                //        o.at(simplex_X, simplex_Y, simplex_Z) << std::endl;
            }
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

    CertHandler::I()->init();
    CertHandler::I()->generate("ServerCert", "Alpha 0.0.1 Server Certificate");

    ServerNetworkManager::I()->init(ServerConfigParser::I()->getLoginServerPort(),
                                    ServerConfigParser::I()->getCertPath()+"ServerCert.key",
                                    ServerConfigParser::I()->getServerListenerThreads());


    return 0;
}