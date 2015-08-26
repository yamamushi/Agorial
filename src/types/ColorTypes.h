//
// Created by Jonathan Rumion on 8/17/15.
//

#ifndef AGORIAL_COLORTYPE_H
#define AGORIAL_COLORTYPE_H

struct ColorRGB{

    int r;
    int g;
    int b;

    ColorRGB(int R=0, int G=0, int B=0) : r(R), g(G), b(B) {};

    bool operator!=(const ColorRGB& color2) const {
        if(r != color2.r || g != color2.g || b != color2.b)
            return true;
        else
            return false;
    }

    bool operator==(const ColorRGB& color2) const {
        if(r == color2.r && g == color2.g && b == color2.b)
            return true;
        else
            return false;
    }

};

#endif //AGORIAL_COLORTYPE_H
