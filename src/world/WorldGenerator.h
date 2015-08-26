//
// Created by Jonathan Rumion on 8/25/15.
//

#ifndef AGORIAL_WORLDGENERATOR_H
#define AGORIAL_WORLDGENERATOR_H

#include <string>
#include <utility>
#include <vector>

class WorldGenerator {

public:

    WorldGenerator(){};
    ~WorldGenerator(){};


private:

    int m_worldX, m_worldY, m_worldZ;

    std::vector<std::pair<std::string, int> > m_layerSeeds;


};


#endif //AGORIAL_WORLDGENERATOR_H
