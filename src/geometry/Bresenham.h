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

typedef std::vector<std::pair<int, int> > Bresenham_2dPathPoints;

typedef std::vector<std::tuple<int, int, int> > Bresenham_3dPathPoints;

// Use these to fill a path struct
void BresenhamCheck2D(int x1, int y1, int const x2, int const y2, Bresenham_2dPathPoints *path);
void BresenhamCheck3D(int x1, int y1, int z1, const int x2, const int y2, const int z2, Bresenham_3dPathPoints *path);

// Use these to validate a specific point from a path struct
bool BresenhamDoesIntersect(Bresenham_2dPathPoints pathPoints, int pointX, int pointY);
bool BresenhamDoesIntersect(Bresenham_3dPathPoints pathPoints, int pointX, int pointY, int pointZ);

struct point{int x; int y;};

bool pointInEllipse(point pointTest, point center, int width, int height);


#endif //AGORIAL_BRESENHAM_H
