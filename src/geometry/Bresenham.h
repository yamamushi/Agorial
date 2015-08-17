//
// Created by Jonathan Rumion on 8/17/15.
//
// These functions will write out their associated paths to 2dpath or 3dpath structs.
// To draw the generated lines, one needs to check the pathPoints of their associated structs.
//

#ifndef AGORIAL_BRESENHAM_H
#define AGORIAL_BRESENHAM_H

#include <string>
#include <vector>
#include <utility>



struct Bresenham_2dpath{

std::vector<std::pair<int, int> > pathPoints;

};


struct Bresenham_3dpath{

    std::vector<std::tuple<int, int, int> > pathPoints;

};


void BresenhamCheck2D(int x1, int y1, int const x2, int const y2, Bresenham_2dpath path);
void BresenhamCheck3D(int x1, int y1, int z1, const int x2, const int y2, const int z2, Bresenham_3dpath path);


#endif //AGORIAL_BRESENHAM_H
